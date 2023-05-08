#include <Window.hpp>
#include <Input.hpp>

#include <iostream>

int main(int argc,char** argv)
{
    KitsunEngine::Window window(1280,720);

    window.setTitle("Balls");

    while(window.isRunning())
    {
        window.refreshMessages();
        auto msg = window.getMessage();
        auto mpos = KitsunEngine::Mouse::getPosition();
        KitsunEngine::Utils::Date date;
        std::cout << date << std::endl;
        switch(msg.type)
        {
            case KitsunEngine::Window::MessageState::Type::MouseMove:
                //std::cout << mpos << std::endl;
                break;
            case KitsunEngine::Window::MessageState::Type::Close:
                return EXIT_SUCCESS;
            case KitsunEngine::Window::MessageState::Type::KeyboardDown:
                std::cout << KitsunEngine::Keyboard::isKeyPressed(VK_F1) << std::endl;
                break;
        }
        
    }

    return EXIT_SUCCESS;
}