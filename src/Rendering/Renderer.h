#ifndef RENDERER_H
#define RENDERER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "OpenGLInfo.h"

#include <vector>

namespace Mgrs
{
    class ShaderMgr;
}

namespace Rendering
{
    class RenderingComponent;
    class Renderer
    {
    public:
        Renderer(const WindowInfo & windowInfo,
                 const ContextInfo & contextInfo);
        ~Renderer();

        bool init();
        void update(float millis);
        bool shutdown();

        void addObjectToRender(RenderingComponent * object);

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

        std::vector<RenderingComponent *> toRender;

    private:
        bool initSDL(const WindowInfo & windowInfo, const ContextInfo & contextInfo);
        bool initGLEW();

        unsigned int program;
    };
} // end Rendering

#endif // RENDERER_H
