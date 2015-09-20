#include "Recreito.h"

#include "Rendering/OpenGLInfo.h"
#include "Rendering/Renderer.h"
#include "Rendering/RenderingComponent.h"

#include "Core/GameObject.h"

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

    if (initialized)
    {
        initScene();
    }

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

//    cube = new Core::Cube(*renderer);
//    renderer->addObjectToRender(cube->renderingComponent);
      object = new Core::GameObject();
      object->renderingComponent = new Rendering::RenderingComponent(*object, "Light");
      object->renderingComponent->init(*renderer, "../resources/models/nanosuit/nanosuit.obj");
      renderer->addObjectToRender(object->renderingComponent);

      object2 = new Core::GameObject();
      object2->position = glm::vec3(10, 0, 0);
      object2->renderingComponent = new Rendering::RenderingComponent(*object2, "3D Simple");
      object2->renderingComponent->init(*renderer, "../resources/models/nanosuit/nanosuit.obj");
      renderer->addObjectToRender(object2->renderingComponent);
}
