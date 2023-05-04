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
    LRESULT CALLBACK Window::WindowProc(HWND handle,UINT message,WPARAM wparam,LPARAM lparam)
    {
    switch(message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_PAINT:
            {

            }
            return 0;
    }
    return DefWindowProc(handle,message,wparam,lparam);
    }
    Window::Window(unsigned int width,unsigned int height): logger("Window")
    {
        instance = (HINSTANCE)GetModuleHandle(NULL);

        GetStartupInfo(&info);

        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = instance;
        wc.lpszClassName = WINDOWS_CLASS_NAME;

        RegisterClass(&wc);

        handle = CreateWindow(
            WINDOWS_CLASS_NAME,
            L"",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,CW_USEDEFAULT,width,height,
            NULL,NULL,
            instance,NULL
        );

        if(handle == NULL)
        {
            logger.error("Couldn't create a Window!");
            exit(EXIT_FAILURE);
        }
        show();
    }
    void Window::show()
    {
        ShowWindow(handle,info.wShowWindow);
    }
    void Window::hide()
    {
        
    }
    void Window::listen()
    {
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