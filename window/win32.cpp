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

PIXELFORMATDESCRIPTOR pfd =
{
    sizeof(PIXELFORMATDESCRIPTOR),
    1,
    PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
    PFD_TYPE_RGBA,        // The kind of framebuffer. RGBA or palette.
    32,                   // Colordepth of the framebuffer.
    0, 0, 0, 0, 0, 0,
    0,
    0,
    0,
    0, 0, 0, 0,
    24,                   // Number of bits for the depthbuffer
    8,                    // Number of bits for the stencilbuffer
    0,                    // Number of Aux buffers in the framebuffer.
    PFD_MAIN_PLANE,
    0,
    0, 0, 0
};

namespace KitsunEngine
{
    Window::State* Window::getWindowState(HWND handle)
    {
        LONG_PTR ptr = GetWindowLongPtr(handle,GWLP_USERDATA);
        Window::State *state = reinterpret_cast<Window::State*>(ptr);
        return state;
    }
    int Window::getPixelFormat()
    {
        return pixelFormat;
    }
    LRESULT CALLBACK Window::WindowProc(HWND handle,UINT message,WPARAM wparam,LPARAM lparam)
    {
        Window::State *state;
        if(message == WM_CREATE)
        {
            CREATESTRUCT *create = reinterpret_cast<CREATESTRUCT*>(lparam);
            state = reinterpret_cast<Window::State*>(create->lpCreateParams);
            SetWindowLongPtr(handle,GWLP_USERDATA,(LONG_PTR)state);
            state->message.type = Window::MessageState::Type::Ready;

            state->window->gdi = GetDC(handle);
            state->window->pixelFormat = ChoosePixelFormat(state->window->gdi,&pfd);
            SetPixelFormat(state->window->gdi,state->window->pixelFormat,&pfd);
        } 
        else state = getWindowState(handle);
        switch(message)
        {
            default:
                if(state != nullptr) state->message.type = Window::MessageState::Type::Nothing;
                break;
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
            case WM_PAINT:
                {
                    PAINTSTRUCT ps;
                    HDC hdc = BeginPaint(handle, &ps);

                    

                    EndPaint(handle, &ps);
                }
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
    Utils::Rectangle Window::getRect()
    {
        RECT rect;
        GetWindowRect(handle,&rect);
        return Utils::Rectangle(rect);
    }
    Window::operator HINSTANCE()
    {
        return instance;
    }
    Window::operator HWND()
    {
        return handle;
    }
    Window::operator HDC()
    {
        return gdi;
    }
}