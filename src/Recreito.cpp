#include "Recreito.h"

#include "Rendering/OpenGLInfo.h"
#include "Rendering/Renderer.h"
#include "Core/Triangle.h"
#include "Core/Square.h"
#include "Core/Plane.h"

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

    Core::Plane * plane = new Core::Plane(*renderer);
    renderer->addObjectToRender(plane->renderingComponent);
}
