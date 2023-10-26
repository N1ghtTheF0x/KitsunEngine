#include <N1ghtTheF0x/KitsunEngine.hpp>
#include <N1ghtTheF0x/LibKitsune/Logger.hpp>

static N1ghtTheF0x::LibKitsune::Logger _mainLogger = "Main";

#ifdef _WIN64
#include <windows.h>

int CALLBACK WinMain(
    HINSTANCE   hInstance,
    HINSTANCE   hPrevInstance,
    LPSTR       lpCmdLine,
    int         nCmdShow)
{
    int argc = __argc;char** argv = __argv;
#else
int main(int argc,char** argv)
{
#endif
    try
    {
        N1ghtTheF0x::KitsunEngine::Application app;
        int result = app.run();
        return result;
    }
    catch(const std::exception& e)
    {
        _mainLogger.error() << e.what() << std::endl;
    }
    catch(...)
    {
        _mainLogger.error() << "Damn, something REAL shit happend..." << std::endl;
    }
    return EXIT_FAILURE;
}