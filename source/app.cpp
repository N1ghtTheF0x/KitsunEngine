#include <N1ghtTheF0x/KitsunEngine/App.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        static LibKitsune::Logger _appLogger = "Application";
        Application::Application()
        {

        }
        Application::Application(int argc,char** argv)
        {
            // TODO: make argc,argv into _argv
        }   
        Application::~Application()
        {
            if(_hasContext)
                delete _context;
        }
        int Application::run()
        {
            _init();
            while (_running)
            {
                _displayEvents();
                _update();
                _rendering();
            }
            
            _clean();
            return EXIT_SUCCESS;
        }
        const Core::Context *Application::context() const
        {
            return _context;
        }
        const Core::Display &Application::display() const
        {
            return _display;
        }
        Core::Context *Application::createContext(Core::Context::Type type)
        {
            using T = Core::Context::Type;
            if(_hasContext)
                delete _context;
            _hasContext = false;
            switch(type)
            {
                case T::None:
                default:
                    _appLogger.warn() << "Cannot have no Context!" << std::endl;
                    exit(EXIT_FAILURE);
                    break;
#ifdef PLATTFORM_DESKTOP
                case T::OpenGL:
                    _context = new Core::OpenGLContext(_display);
                    _hasContext = true;
                    break;
#endif
            }
            return _context;
        }
        bool Application::hasContext() const
        {
            return _hasContext;
        }
        void Application::_update()
        {
            
        }
        void Application::_rendering()
        {
            if(_hasContext)
            {
                _context->clear();
                if(_context->type() == Core::Context::Type::OpenGL)
                {
                    Core::OpenGLContext *opengl = (Core::OpenGLContext *)_context;
                    opengl->clear(1,0,0);
                }
                _context->swap();
            }
        }
    }
}