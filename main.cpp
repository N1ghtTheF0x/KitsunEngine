#include <Window.hpp>
#include <Input.hpp>
#include <Renderer.hpp>
#include <Image.hpp>

#include <iostream>

void draw(KitsunEngine::Window &win)
{
    auto size = win.getRect().getSize();
    glViewport(0,0,size.getX(),size.getY());
    glClearColor(0.5,0.5,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.5f, -0.5f);    // x, y
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f( 0.5f, -0.5f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f( 0.5f,  0.5f);
    glEnd();
    glFlush();
#ifdef OS_LINUX
    glXSwapBuffers(win,win);
#endif
}

#ifdef OS_WINDOWS
int APIENTRY WinMain(HINSTANCE instance,HINSTANCE prevInstance,PSTR cmdline,int cmdshow)
{
    char** argv = __argv;int argc = __argc;
#else
int main(int argc,char** argv)
{
#endif
    KitsunEngine::Utils::Logger logger("Main");
    KitsunEngine::Window window(1280,720);
    KitsunEngine::Context ctx(window
#ifdef OS_LINUX
    ,window,window
#endif
    );

    window.setTitle("Balls");

    KitsunEngine::Utils::Color color(0xAA,0xBB,0xCC);
    KitsunEngine::Utils::Date date(0);
    KitsunEngine::Utils::File bmpFile("test.bmp",std::ios::binary | std::ios::out | std::ios::in);
    KitsunEngine::Utils::Buffer bmpBuf(bmpFile);
    KitsunEngine::ImageFormats::BMP bmp;

    bmpBuf.read((char*)&bmp,sizeof(bmp));

    unsigned int numColor = color;

    logger.info(KitsunEngine::Utils::File::getCWD());

    glEnable(GL_DEPTH_TEST);

    while(window.isRunning())
    {
        window.refreshMessages();
        auto msg = window.getMessage();
        switch(msg)
        {
            case KitsunEngine::Window::MessageType::Close:
                return EXIT_SUCCESS;
            case KitsunEngine::Window::MessageType::Draw:
                draw(window);
                break;
            case KitsunEngine::Window::MessageType::KeyboardDown:
                std::cout << KitsunEngine::Keyboard::getLastKeyPressed() << std::endl;
                break;
            default:
                break;
        }
    }

    return EXIT_SUCCESS;
}