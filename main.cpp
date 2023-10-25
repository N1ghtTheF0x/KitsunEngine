#include <N1ghtTheF0x/KitsunEngine.hpp>

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
    N1ghtTheF0x::KitsunEngine::Application app;
    int result = app.run();
    return result;
}