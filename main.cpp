#include <Window.hpp>
#include <Input.hpp>
#include <Renderer.hpp>
#include <Image.hpp>

#include <iostream>

const KitsunEngine::Utils::Logger logger("Main");

void draw_loop(KitsunEngine::Window &win,KitsunEngine::Context &ctx)
{
    auto rect = win.getRect();
    KitsunEngine::Context::setViewport(rect);
    glClearColor(0.5,0.5,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    KitsunEngine::Utils::Rectangle a(-0.5,0.5,0.5,0.5);

    ctx.drawRectangle(a,0xFF000000);
    /*glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.5f, -0.5f);    // x, y
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f( 0.5f, -0.5f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f( 0.5f,  0.5f);
    glEnd();*/
    ctx.swapBuffers();
}

void bmp_file()
{

}

int kitsunmain(int argc,char** argv)
{
    KitsunEngine::Window window(1280,720);
    KitsunEngine::Context ctx(window
#ifdef OS_LINUX
    ,window,window
#endif
    );

    window.setTitle("Balls");

    KitsunEngine::Utils::Color color(0xAA,0xBB,0xCC);

    unsigned int numColor = color;

    logger.info(KitsunEngine::Utils::File::getCWD());

    glEnable(GL_DEPTH_TEST);

    KitsunEngine::Utils::Date oldTime;
    KitsunEngine::Utils::Date curTime;
    while(window.isRunning())
    {
        oldTime = curTime;
        curTime = KitsunEngine::Utils::Date();
        logger.info(std::to_string(curTime - oldTime) + "ms");
        window.refreshMessages();
        auto msg = window.getMessage();
        switch(msg)
        {
            case KitsunEngine::Window::MessageType::Draw:
                draw_loop(window,ctx);
                break;
            case KitsunEngine::Window::MessageType::KeyboardDown:
                std::cout << KitsunEngine::Keyboard::getLastKeyPressed() << std::endl;
                break;
        }
    }

    return EXIT_SUCCESS;
}

#ifdef OS_WINDOWS
int APIENTRY WinMain(HINSTANCE instance,HINSTANCE prevInstance,PSTR cmdline,int cmdshow)
{
    int argc = __argc;
    char** argv = __argv;
    KitsunEngine::Utils::Win32::initConsole();
#else
int main(int argc,char** argv)
{
#endif
    try
    {
        return kitsunmain(argc,argv);
    }
    catch(std::exception &error)
    {
        std::cerr << "Exception Caught!" << std::endl << std::endl << error.what() << std::endl << std::endl;
    }
    catch(...)
    {
        std::cerr << "Holy shit!" << std::endl << "Something BAD happend!" << std::endl << std::endl;
    }
    KitsunEngine::Utils::Logger::printStacktrace();
    std::cerr << std::endl << "Send this to the developer!" << std::endl;
    return EXIT_FAILURE;
}