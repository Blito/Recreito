#ifndef RENDERER_H
#define RENDERER_H

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "OpenGLInfo.h"

#include <vector>
#include <unordered_map>
#include <memory>

#include <glm/mat4x4.hpp>

namespace Mgrs
{
    class ShaderMgr;
}

namespace Core
{
    class GameObject;
}

namespace Rendering
{
    class RenderingComponent;
    class Shader;
    class Mesh;
    class Renderer
    {
    public:
        Renderer(const WindowInfo & windowInfo,
                 const ContextInfo & contextInfo);
        ~Renderer();

        bool init();
        void update(float millis);
        bool shutdown();

        /**
         * @brief newComponent Creates a new RenderingComponent
         */
        std::unique_ptr<RenderingComponent> newComponent(const Core::GameObject & parent,
                                                         const Shader & shaderProgram,
                                                         const Mesh * mesh = nullptr);

        bool isQuit() const { return shouldQuit; }

        const Mgrs::ShaderMgr * getShaderMgr() const;

    protected:
        void draw(RenderingComponent & object);

        void setProjMatrix(const Shader * shader);

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
        std::unordered_map<const Shader *, std::vector<RenderingComponent*>> toRender;

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
