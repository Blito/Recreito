#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <iostream>

#include "ShaderMgr.h"
#include "Renderable.h"

GLuint program;
GLuint vertex_array_object;

Core::Renderable * triangle;
Mgrs::ShaderMgr * shaderMgr;

void init()
{
    glEnable(GL_DEPTH_TEST);
 
    triangle = new Core::Renderable("");

    //load and compile shaders
    shaderMgr = new Mgrs::ShaderMgr();
    program = shaderLoader.createProgram("../src/shaders/Vertex_Shader.glsl",
                                        "../src/shaders/Fragment_Shader.glsl");

    std::cout << "Program " << program << " created." << std::endl;

    //generate the vertex array
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void shutdown()
{
    delete[] shaderMgr;
}

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

    SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);

    glewExperimental = GL_TRUE;
    glewInit();

    init();

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        /* Check for new events */
        while(SDL_PollEvent(&event))
        {
            /* If a quit event has been sent */
            if (event.type == SDL_QUIT)
            {
                /* Quit the application */
                quit = true;
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

    glDeleteProgram(program);

    SDL_GL_DeleteContext(context);
    SDL_Quit();
    return 0;
}
