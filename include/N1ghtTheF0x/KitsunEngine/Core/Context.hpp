#ifndef __N1GHTTHEF0X_KITSUNENGINE_CORE_CONTEXT_HPP
#define __N1GHTTHEF0X_KITSUNENGINE_CORE_CONTEXT_HPP

#include "Display.hpp"
#include "../Utils/Macros.hpp"

namespace N1ghtTheF0x
{
    namespace KitsunEngine
    {
        namespace Core
        {
            KITSUNENGINE_CLASS(Context)
            class Context
            {
            public:
                enum struct Type
                {
                    None,
#ifdef PLATTFORM_DESKTOP
                    OpenGL,
#endif
                };
            protected:
                bool _ready = false;
            public:
                virtual void clear() = 0;
                virtual void swap() = 0;
                virtual Type type() const = 0;
            };
#ifdef PLATTFORM_DESKTOP
            KITSUNENGINE_CLASS(OpenGLContext)
            class OpenGLContext : public Context
            {
            private:
                SDL_GLContext _context;
                PtrDisplay _display;
            public:
                OpenGLContext(Display &display);

                void clear() override;
                void clear(float red,float green,float blue,float alpha = 1.0f);
                void swap() override;
                Type type() const override;
            };
#endif
        }
    }
}

#endif