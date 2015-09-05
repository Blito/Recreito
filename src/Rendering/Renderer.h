#ifndef RENDERER_H
#define RENDERER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "OpenGLInfo.h"

#include <vector>
#include <map>
#include <unordered_map>

#include <glm/mat4x4.hpp>

namespace Mgrs
{
    class ShaderMgr;
}

namespace Rendering
{
    class RenderingComponent;
    class Shader;
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

        const Mgrs::ShaderMgr * getShaderMgr() const;

    protected:
        void setProjMatrix(Shader * shader);

        const WindowInfo & windowInfo;
        class SDL_Window * window;

        const ContextInfo & contextInfo;
        SDL_GLContext context;

        bool initialized = false;
        bool deinitialized = false;
        bool shouldQuit = false;

        Mgrs::ShaderMgr * shaderMgr;

        class Camera * camera;
        class Light * light;
        std::map<Shader*, std::vector<RenderingComponent*>> toRender;

        glm::mat4 proj;
        float fovDeg, nearPlane, farPlane;

        float magicI = 0.0f;

    private:
        static constexpr const char * projUniformName = "projection";

        bool initSDL(const WindowInfo & windowInfo, const ContextInfo & contextInfo);
        bool initGLEW();
    };
} // end Rendering

#endif // RENDERER_H
