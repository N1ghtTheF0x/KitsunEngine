#include <Window.hpp>
#include <Input.hpp>

#include <GL/glx.h>

GLint vinfo_attr[] = {
    GLX_RGBA,GLX_DEPTH_SIZE,24,GLX_DOUBLEBUFFER,None
};

#define LINUX_EVENTMASK ExposureMask | \
                        KeyPressMask | \
                        KeyReleaseMask | \
                        ButtonPressMask | \
                        ButtonReleaseMask | \
                        PointerMotionMask | \
                        SubstructureNotifyMask

namespace KitsunEngine
{
    Window::operator Display*()
    {
        return dis;
    }
    Window::operator X11Window &()
    {
        return win;
    }
    Window::operator XVisualInfo *()
    {
        return vinfo;
    }
    Colormap &Window::getColormap()
    {
        return cmap;
    }
    Window::Window(unsigned int width,unsigned int height): logger("Window")
    {
        running = false;
        logger.info("Creating Window using X11...");

        curState = new State;
        curState->window = this;

        XSetWindowAttributes swa;

        dis = XOpenDisplay((char*)0);
        screen = DefaultScreen(dis);
        auto root = DefaultRootWindow(dis);

        vinfo = glXChooseVisual(dis,screen,vinfo_attr);
        if(vinfo == NULL)
        {
            logger.error("Couldn't choose Visual Info!");
            exit(EXIT_FAILURE);
        }
        cmap = XCreateColormap(dis,root,vinfo->visual,AllocNone);

        swa.colormap = cmap;
        swa.event_mask = LINUX_EVENTMASK;

        win = XCreateWindow(dis,root,0,0,width,height,0,vinfo->depth,InputOutput,vinfo->visual,CWColormap | CWEventMask,&swa);

        XMapWindow(dis,win);

        setTitle(LINUX_DEFAULT_WINDOW_TITLE);

        logger.info("Created Window!");
        running = true;
    }
    Window::~Window()
    {
        logger.info("Destroying Window...");
        close();
    }
    void Window::show()
    {

    }
    void Window::close()
    {
        running = false;
        XDestroyWindow(dis,win);
        XCloseDisplay(dis);
    }
    void Window::hide()
    {
        XIconifyWindow(dis,win,screen);
    }
    void Window::setTitle(const char* title)
    {
        XStoreName(dis,win,title);
        XClassHint *hint = XAllocClassHint();
        if(hint)
        {
            hint->res_name = hint->res_class = (char*)title;
            XSetClassHint(dis,win,hint);
            XFree(hint);
        }
    }
    void Window::refreshMessages()
    {
        XEvent event;
        using EventType = Window::MessageType;

        XNextEvent(dis,&event);

        switch(event.type)
        {
            case Expose:
                curState->message = EventType::Draw;
                break;
            case CreateNotify:
                curState->message = EventType::Ready;
                break;
            case DestroyNotify:
                curState->message = EventType::Close;
                close();
                break;
            case ClientMessage:
                
                break;
            case KeyPress:
                {
                    char text[0xFF];
                    KeySym key;
                    XLookupString(&event.xkey,text,255,&key,0);
                    curState->message = event.xkey.type == KeyPress ? EventType::KeyboardDown : EventType::KeyboardUp;
                    Keyboard::setKeyState(text[0],event.xkey.type == KeyPress);
                    if(event.xkey.type == KeyPress) 
                    Keyboard::setLastKeyPressed(text[0]);
                }
                break;
            case ButtonPress:
                curState->message = event.xbutton.type == ButtonPress ? EventType::MouseDown : EventType::MouseUp;
                Mouse::setButtonPressed((Mouse::Button)(event.xbutton.button-1),event.xbutton.type == ButtonPress);
                break;
            case MotionNotify:
                curState->message = EventType::MouseMove;
                Mouse::setPosition(event.xbutton.x,event.xbutton.y);
                break;
        }
    }
    Utils::Rectangle Window::getRect()
    {
        XWindowAttributes attr;
        XGetWindowAttributes(dis,win,&attr);
        return Utils::Rectangle(attr.x,attr.y,attr.width,attr.height);
    }
}