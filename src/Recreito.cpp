#include "Recreito.h"

#include "systems/rendering/OpenGLInfo.h"
#include "systems/rendering/Renderer.h"
#include "systems/rendering/RenderingComponent.h"
#include "systems/rendering/models/ModelFactory.h"
#include "systems/rendering/models/Model.h"

#include "systems/rendering/shaders/ShaderMgr.h"

#include "core/GameObject.h"
#include "core/Scene.h"

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
    scene = new Core::Scene();

    Rendering::ASSIMPModelFactory modelFactory;
    auto model = modelFactory.createModel("../resources/models/nanosuit/nanosuit.obj");

//    auto object = new Core::GameObject(renderer->getShaderMgr()->getDefaultProgram(), model);
//    scene->addGameObject(object);

//    object = new Core::GameObject(renderer->getShaderMgr()->getProgram("3D Simple"),
//                                  model);
//    object->position = glm::vec3(10, 0, 0);
//    scene->addGameObject(object);

    for (int x = -4; x < 4; x++)
    {
        for (int y = -4; y < 4; y++)
        {
            auto object = new Core::GameObject();
            object->addRenderingComponent(*renderer, *renderer->getShaderMgr()->getDefaultProgram(), model);
            object->position = glm::vec3(x*10, 0, y*10);
            scene->addGameObject(object);
        }
    }
}
