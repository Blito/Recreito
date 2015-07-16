#ifndef RENDERER_H
#define RENDERER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "OpenGLInfo.h"

namespace Mgrs
{
    class ShaderMgr;
}

namespace Core
{
    class Renderable;
}

namespace Rendering
{
    class Renderer
    {
    public:
        Renderer(const WindowInfo & windowInfo,
                 const ContextInfo & contextInfo);
        ~Renderer();

        bool init();
        bool shutdown();

        void update(float millis);

        bool isQuit() const { return shouldQuit; }

    protected:
        const WindowInfo & windowInfo;
        class SDL_Window * window;

        const ContextInfo & contextInfo;
        SDL_GLContext context;

        bool initialized = false;
        bool deinitialized = false;
        bool shouldQuit = false;

        Mgrs::ShaderMgr * shaderMgr;

    private:
        bool initSDL(const WindowInfo & windowInfo, const ContextInfo & contextInfo);
        bool initGLEW();

        // This should not be here eventually
        unsigned int program;
        unsigned int vertex_array_object;
        Core::Renderable * triangle;
    };
} // end Rendering

#endif // RENDERER_H
