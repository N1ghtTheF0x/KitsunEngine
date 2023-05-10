#include <Window.hpp>

namespace KitsunEngine
{
    bool Window::isRunning()
    {
        return running;
    }
    Window::State* Window::getState()
    {
        return curState;
    }
    Window::MessageState &Window::getMessage()
    {
        return curState->message;
    }
    void Window::setTitle(std::string title)
    {
        setTitle(title.c_str());
    }
    void Window::setTitle(std::stringstream title)
    {
        setTitle(title.str());
    }
}