#include "Renderer.h"

#include <iostream>

#include "RenderingComponent.h"
#include "../../gameobjects/Camera.h"
#include "Light.h"
#include "models/ModelFactory.h"
#include "shaders/ShaderMgr.h"
#include "shaders/Shader.h"

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

    auto names = new std::string[4] { "Simple", "Textured", "3D Simple", "Light" };

    shaderMgr->createProgram(names[0],
                             "../src/systems/rendering/shaders/2d.vert",
                             "../src/systems/rendering/shaders/color.frag");

    shaderMgr->createProgram(names[1],
                             "../src/systems/rendering/shaders/2d.vert",
                             "../src/systems/rendering/shaders/texture.frag");

    shaderMgr->createProgram(names[2],
                             "../src/systems/rendering/shaders/3d.vert",
                             "../src/systems/rendering/shaders/color.frag");

    shaderMgr->createProgram(names[3],
                             "../src/systems/rendering/shaders/3d.vert",
                             "../src/systems/rendering/shaders/color_light.frag",
                             true /*setAsDefault*/);

    camera = new Camera();
    camera->position = glm::vec3(-10, 20, -10);

    camera->lookAt(0, 15, 0);

    ASSIMPModelFactory modelFactory;
    auto model = modelFactory.createModel("../resources/models/muffin/muffin.obj");

    light = new Light(*this, *shaderMgr->getProgram("Light"),model);

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
    glClearColor(0.1, 0.1, 0.1, 1.0);

    for (auto & shader_object : toRender)
    {
        // enable shader program
        shader_object.first->enable();

        setProjMatrix(shader_object.first);

        camera->enable(shader_object.first);

        light->enable(shader_object.first);

        for (auto object : shader_object.second)
        {
            draw(*object);
        }
    }

    //camera->position = glm::vec3(20*std::sin(magicI), 25, -20*std::cos(magicI));
    magicI += 0.005;

    light->position = glm::vec3(20*std::sin(magicI/2.0)+8, 10, 20*std::cos(magicI/2.0f));

    camera->lookAt(light->position.x, light->position.y, light->position.z);

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

std::unique_ptr<RenderingComponent> Renderer::newComponent(const Core::GameObject & parent,
                                                           const Shader & shaderProgram,
                                                           const Mesh * mesh)
{
    auto component = std::unique_ptr<RenderingComponent>(new RenderingComponent(parent, shaderProgram, mesh));

    // Add it to rendering list
    toRender[&shaderProgram].push_back(component.get());

    return component;
}

const Mgrs::ShaderMgr * Renderer::getShaderMgr() const
{
    return shaderMgr;
}

void Renderer::draw(RenderingComponent & object)
{
    // Send uniform values to GPU
    auto modelMatrix = glm::translate(glm::mat4(1), object.position);

    GLint modelLoc = object.shaderProgram.getUniform("model");

    if (modelLoc > -1)
    {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    }

    // Draw the mesh associated with this element
    if (object.mesh)
    {
        object.mesh->draw(object.shaderProgram);
    }
}

void Renderer::setProjMatrix(const Shader * shader)
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
