#ifndef RENDERER_H
#define RENDERER_H

#include "OpenGLInfo.h"

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

    protected:
        bool initialized = false;
        bool shouldQuit = false;

        class Mgrs::ShaderMgr * shaderMgr;
    };
} // end Rendering

#endif // RENDERER_H
