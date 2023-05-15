#include <Renderer.hpp>

#define CALC_COORD(coord,size) (2*(coord/size))-1

namespace KitsunEngine
{
    void Context::drawRectangle(Utils::Rectangle &rect,Utils::Color color)
    {
        Utils::Rectangle viewport = getViewport();
        auto width = viewport.getWidth();
        auto height = viewport.getHeight();
        auto bbox = rect.getBBox();

        glBegin(GL_QUADS);
            glColor4ub(color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
            glVertex2d(CALC_COORD(bbox.left,width),CALC_COORD(bbox.top,height));
            glVertex2d(CALC_COORD(bbox.right,width),CALC_COORD(bbox.top,height));
            glVertex2d(CALC_COORD(bbox.right,width),CALC_COORD(bbox.bottom,height));
            glVertex2d(CALC_COORD(bbox.left,height),CALC_COORD(bbox.bottom,height));
        glEnd();
        auto a = glBegin;
    }
}