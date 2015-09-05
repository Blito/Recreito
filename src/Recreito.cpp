#include "Recreito.h"

#include "Rendering/OpenGLInfo.h"
#include "Rendering/Renderer.h"
#include "Core/Triangle.h"
#include "Core/Square.h"
#include "Core/Cube.h"

#include <cmath>

Recreito::Recreito()
    : renderer(nullptr)
{

}

Recreito::~Recreito()
{
    if (!deinitialized)
    {
        shutdown();
    }
}

void Recreito::run()
{
    if (!init())
    {
        return;
    }

    while (!renderer->isQuit())
    {
        renderer->update(1000);

        magicI += 0.005f;
        cube->position = glm::vec3(5 * std::sin(magicI), 0.0f, 5 * std::cos(magicI));
    }

    shutdown();
}

bool Recreito::init()
{
    Rendering::WindowInfo window("Recreito",
                                 800, 600,
                                 100, 100,
                                 false);
    Rendering::ContextInfo context(4, 3, true);
    renderer = new Rendering::Renderer(window, context);

    initialized = renderer->init();

    initScene();

    return initialized;
}

bool Recreito::shutdown()
{
    delete renderer;

    return true;
}

void Recreito::initScene()
{
//    Core::Triangle * triangle= new Core::Triangle(*renderer);
//    renderer->addObjectToRender(triangle->renderingComponent);

//    Core::Square * square = new Core::Square(*renderer);
//    renderer->addObjectToRender(square->renderingComponent);

    cube = new Core::Cube(*renderer);
    renderer->addObjectToRender(cube->renderingComponent);
}
