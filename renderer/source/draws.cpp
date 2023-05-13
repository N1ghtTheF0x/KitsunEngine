#include <Renderer.hpp>

namespace KitsunEngine
{
    void Context::drawRectangle(Utils::Rectangle &rect,Utils::Color color)
    {
        glBegin(GL_QUADS);
            glColor4ub(color.getRed(),color.getGreen(),color.getBlue(),color.getAlpha());
            auto bbox = rect.getBBox();
            glVertex2d(bbox.left,bbox.top);
            glVertex2d(bbox.right,bbox.top);
            glVertex2d(bbox.right,bbox.bottom);
            glVertex2d(bbox.left,bbox.bottom);
        glEnd();
    }
}