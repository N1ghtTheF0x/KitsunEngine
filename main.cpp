#include <Window.hpp>

int main(int argc,char** argv)
{
    KitsunEngine::Window window(1280,720);

    window.setTitle("Balls");
    window.listen();

    return EXIT_SUCCESS;
}