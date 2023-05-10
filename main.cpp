#include <Window.hpp>
#include <Input.hpp>
#include <Renderer.hpp>

#include <iostream>

void draw(KitsunEngine::Window &win)
{
    auto size = win.getRect().getSize();
    glViewport(0,0,size.getX(),size.getY());
    glClearColor(0.5,0.5,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
        glColor3f(1.0f, 0.0f, 0.0f); // Red
        glVertex2f(-0.5f, -0.5f);    // x, y
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
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

    unsigned int numColor = color;

    auto opengl = glGetString(GL_VERSION);
    auto vendor = glGetString(GL_VENDOR);
    auto openglu = gluGetString(GLU_VERSION);

    std::string OpenGL;
        OpenGL
        .append((const char*)opengl).append(" | ")
        .append((const char*)vendor).append(" | ")
        .append((const char*)openglu);

    logger.info(OpenGL);
    logger.info(KitsunEngine::Utils::File::getCWD());

    glEnable(GL_DEPTH_TEST);

    while(window.isRunning())
    {
        window.refreshMessages();
        auto msg = window.getMessage();
        auto mpos = KitsunEngine::Mouse::getPosition();
        auto size = window.getRect().getSize();
        switch(msg.type)
        {
            case KitsunEngine::Window::MessageState::Type::Close:
                return EXIT_SUCCESS;
            case KitsunEngine::Window::MessageState::Type::Draw:
                draw(window);
                break;
            case KitsunEngine::Window::MessageState::Type::KeyboardDown:
                std::cout << KitsunEngine::Keyboard::getLastKeyPressed() << std::endl;
                break;
            default:
                break;
        }
    }

    return EXIT_SUCCESS;
}