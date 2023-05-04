#include <Window.hpp>

#include <iostream>

wchar_t* char2wstr(const char* str)
{
    wchar_t* wstr = new wchar_t[strlen(str)+1];
    MultiByteToWideChar(CP_ACP,0,str,-1,wstr,strlen(str)+1);
    return wstr;
}



namespace KitsunEngine
{
    Window::State* Window::getWindowState(HWND handle)
    {
        LONG_PTR ptr = GetWindowLongPtr(handle,GWLP_USERDATA);
        Window::State *state = reinterpret_cast<Window::State*>(ptr);
        return state;
    }
    LRESULT CALLBACK Window::WindowProc(HWND handle,UINT message,WPARAM wparam,LPARAM lparam)
    {
        Window::State *state;
        if(message == WM_CREATE)
        {
            CREATESTRUCT *create = reinterpret_cast<CREATESTRUCT*>(lparam);
            state = reinterpret_cast<Window::State*>(create->lpCreateParams);
            SetWindowLongPtr(handle,GWLP_USERDATA,(LONG_PTR)state);
        } else state = getWindowState(handle);
        switch(message)
        {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            case WM_PAINT:
                {
                    PAINTSTRUCT ps;
                    HDC hdc = BeginPaint(handle,&ps);

                    FillRect(hdc,&ps.rcPaint,(HBRUSH)(COLOR_WINDOW+1));

                    EndPaint(handle,&ps);
                }
                return 0;
        }
        return DefWindowProc(handle,message,wparam,lparam);
    }
    Window::Window(unsigned int width,unsigned int height): logger("Window")
    {
        logger.info("Creating Window using WIN32...");
        instance = (HINSTANCE)GetModuleHandle(NULL);
        curState = new (std::nothrow)State;

        if(curState == NULL)
        {
            logger.error("Couldn't create State!");
            exit(EXIT_FAILURE);
        }

        curState->window = this;

        GetStartupInfo(&info);

        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = instance;
        wc.lpszClassName = WINDOWS_CLASS_NAME;

        RegisterClass(&wc);

        handle = CreateWindow(
            WINDOWS_CLASS_NAME,
            WINDOWS_DEFAULT_WINDOW_TITLE,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,CW_USEDEFAULT,width,height,
            NULL,NULL,
            instance,curState
        );

        if(handle == NULL)
        {
            logger.error("Couldn't create a Window!");
            exit(EXIT_FAILURE);
        }
        logger.info("Created Window!");
        show();
        threadMessage = std::thread(&Window::messageThreadLoop,this);
        threadMessage.detach();
    }
    void Window::show()
    {
        ShowWindow(handle,SW_SHOW);
    }
    void Window::hide()
    {
        ShowWindow(handle,SW_HIDE);
    }
    void Window::messageThreadLoop()
    {
        logger.info("Listening for messages...");
        MSG msg = {};
        while(GetMessage(&msg,NULL,0,0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    void Window::setTitle(const char* title)
    {
        SetWindowText(handle,char2wstr(title));
    }
}