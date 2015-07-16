#include "Renderer.h"

#include "Renderable.h"
#include "ShaderMgr.h"

using namespace Rendering;

Renderer::Renderer(const WindowInfo & windowInfo, const ContextInfo & contextInfo)
    : windowInfo(windowInfo),
      contextInfo(contextInfo),
      shaderMgr(nullptr)
{

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

    triangle = new Core::Renderable("");

    shaderMgr = new Mgrs::ShaderMgr();
    program = shaderMgr->createProgram("../src/shaders/Vertex_Shader.glsl",
                                       "../src/shaders/Fragment_Shader.glsl");

    //generate the vertex array
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    initialized = sdl && glew;
    return initialized;
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
    glClearColor(1.0, 0.0, 0.0, 1.0);//clear red

    // bind buffers
    triangle->enable();

    //use the created program
    glUseProgram(program);

    //draw 3 vertices as triangles
    glDrawArrays(GL_TRIANGLES, 0, 3);

    SDL_GL_SwapWindow(window);
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
