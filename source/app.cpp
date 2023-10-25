#include <N1ghtTheF0x/KitsunEngine/App.hpp>

#include <iostream>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        Application::Application()
        {

        }
        Application::Application(int argc,char** argv): _argv(argv,argv + argc)
        {
            
        }   
        int Application::run()
        {
            String test = "a";
            std::cout << test.append("b") << std::endl;
            return EXIT_SUCCESS;
        }
    }
}