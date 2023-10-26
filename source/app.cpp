#include <N1ghtTheF0x/KitsunEngine/App.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        LibKitsune::Logger _appLogger = "Application";
        Application::Application()
        {

        }
        Application::Application(int argc,char** argv)
        {
            // TODO: make argc,argv into _argv
        }   
        int Application::run()
        {
            while (_running)
            {
                _displayEvents();
                _update();
                _rendering();
            }
            _clean();
            return EXIT_SUCCESS;
        }
        void Application::_update()
        {
            
        }
        void Application::_rendering()
        {

        }
    }
}