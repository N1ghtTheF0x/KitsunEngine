#include <Window.hpp>

#include <Input.hpp>
#include <iostream>
#include <windowsx.h>

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
        } 
        else state = getWindowState(handle);
        switch(message)
        {
            case WM_KEYDOWN:
                state->message.type = Window::MessageState::Type::KeyboardDown;
                Keyboard::setKeyState(wparam,true);
                Keyboard::setLastKeyPressed(wparam);
                return 0;
            case WM_KEYUP:
                state->message.type = Window::MessageState::Type::KeyboardUp;
                Keyboard::setKeyState(wparam,false);
                return 0;
            case WM_DESTROY:
                state->message.type = Window::MessageState::Type::Close;
                return 0;
            case WM_MOUSEMOVE:
                state->message.type = Window::MessageState::Type::MouseMove;
                Mouse::setPosition(GET_X_LPARAM(lparam),GET_Y_LPARAM(lparam));
                return 0;
        }
        return DefWindowProc(handle,message,wparam,lparam);
    }
    Window::~Window()
    {
        logger.info("Destroying Window...");
    }
    Window::Window(unsigned int width,unsigned int height): logger("Window")
    {
        running = false;
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
        running = true;
        show();
    }
    void Window::show()
    {
        ShowWindow(handle,SW_SHOW);
    }
    void Window::hide()
    {
        ShowWindow(handle,SW_HIDE);
    }
    void Window::refreshMessages()
    {
        MSG msg = {};
        GetMessage(&msg,handle,0,0);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    void Window::setTitle(const char* title)
    {
        SetWindowText(handle,char2wstr(title));
    }
    bool Window::isRunning()
    {
        return running;
    }
    void Window::close()
    {
        running = false;
        DestroyWindow(handle);
        PostQuitMessage(EXIT_SUCCESS);
    }
    Window::State* Window::getState()
    {
        return curState;
    }
    Window::MessageState& Window::getMessage()
    {
        return curState->message;
    }
    Window::operator HINSTANCE()
    {
        return instance;
    }
    Window::operator HWND()
    {
        return handle;
    }
}