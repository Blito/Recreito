#include "Renderer.h"

#include <iostream>

#include "RenderingComponent.h"
#include "Camera.h"
#include "Light.h"
#include "../Mgrs/ShaderMgr.h"
#include "../Rendering/Shader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Rendering;

Renderer::Renderer(const WindowInfo & windowInfo, const ContextInfo & contextInfo)
    : windowInfo(windowInfo),
      contextInfo(contextInfo),
      shaderMgr(nullptr)
{
    fovDeg = 45.0f;
    nearPlane = 0.1f;
    farPlane = 100.0f;
}

Renderer::~Renderer()
{
    if (!deinitialized)
    {
        shutdown();
    }
}

bool Renderer::init()
{
    bool sdl = initSDL(windowInfo, contextInfo);

    bool glew = initGLEW();

    glEnable(GL_DEPTH_TEST);

    shaderMgr = new Mgrs::ShaderMgr();

    shaderMgr->createProgram("Simple",
                             "../src/shaders/2d.vert",
                             "../src/shaders/color.frag");

    shaderMgr->createProgram("Textured",
                             "../src/shaders/2d.vert",
                             "../src/shaders/texture.frag");

    shaderMgr->createProgram("3D Simple",
                             "../src/shaders/3d.vert",
                             "../src/shaders/color.frag");

    shaderMgr->createProgram("Light",
                             "../src/shaders/3d.vert",
                             "../src/shaders/color_light.frag");

    camera = new Camera();
    camera->position = glm::vec3(3, 20, -15);

    camera->lookAt(0, 10, 0);

    light = new Light(*this);
    addObjectToRender(light->renderingComponent);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    proj = glm::perspective(fovDeg,
                            (GLfloat)windowInfo.width / (GLfloat)windowInfo.height, // Ratio
                            nearPlane,
                            farPlane);

    initialized = sdl && glew;
    return initialized;
}

void Renderer::update(float millis)
{
    SDL_Event event;
    /* Check for new events */
    while(SDL_PollEvent(&event))
    {
        /* If a quit event has been sent */
        if (event.type == SDL_QUIT)
        {
            /* Quit the application */
            shouldQuit = true;
        }
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.3, 0.5, 0.5, 1.0);

    for (auto & shader_object : toRender)
    {
        // enable shader program
        shader_object.first->enable();

        setProjMatrix(shader_object.first);

        camera->enable(shader_object.first);

        light->enable(shader_object.first);

        for (auto object : shader_object.second)
        {
            object->enable();
            object->draw();
        }
    }

    camera->position = glm::vec3(5*std::sin(magicI), 10, -10*std::cos(magicI));
    magicI += 0.005;

    light->position = glm::vec3(8, 20*std::sin(magicI/2.0)+10, 20*std::cos(magicI/2.0f));

    SDL_GL_SwapWindow(window);
}

bool Renderer::shutdown()
{
    if (!initialized)
    {
        return true;
    }

    delete shaderMgr;

    SDL_GL_DeleteContext(context);
    SDL_Quit();

    deinitialized = true;
    return deinitialized;
}

void Renderer::addObjectToRender(RenderingComponent * object)
{
    auto shader = shaderMgr->getProgram(object->getShaderProgram());
    if (shader)
    {
        toRender[shader].push_back(object);
    }
    else
    {
        // TODO: Improve error handling
        std::cout << "ShaderMgr: ERROR: Trying to add rendering "
                  << "object with invalid shader program (name: "
                  << object->getShaderProgram() << ")"
                  << std::endl;
    }
}

const Mgrs::ShaderMgr * Renderer::getShaderMgr() const
{
    return shaderMgr;
}

void Renderer::setProjMatrix(Shader * shader)
{
    GLint projLoc = shader->getUniform(projUniformName);

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
}

bool Renderer::initSDL(const WindowInfo & windowInfo,
                       const ContextInfo & contextInfo)
{
    SDL_Init(SDL_INIT_VIDEO);
    if (contextInfo.core)
    {
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, contextInfo.major_version);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, contextInfo.minor_version);

    window = SDL_CreateWindow(windowInfo.title.c_str(),
                                          windowInfo.x, windowInfo.y,
                                          windowInfo.width, windowInfo.height,
                                          SDL_WINDOW_OPENGL);
    context = SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);

    return true;
}

bool Renderer::initGLEW()
{
    glewExperimental = GL_TRUE;
    glewInit();

    return true;
}
