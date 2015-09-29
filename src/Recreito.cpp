#include "Recreito.h"

#include "Rendering/OpenGLInfo.h"
#include "Rendering/Renderer.h"
#include "Rendering/RenderingComponent.h"
#include "Rendering/ModelFactory.h"
#include "Rendering/Model.h"

#include "Mgrs/ShaderMgr.h"

#include "Core/GameObject.h"
#include "Core/Scene.h"

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

    auto object = new Core::GameObject(renderer->getShaderMgr()->getDefaultProgram(), model);
    scene->addGameObject(object);

    object = new Core::GameObject(renderer->getShaderMgr()->getProgram("3D Simple"),
                                  model);
    object->position = glm::vec3(10, 0, 0);
    scene->addGameObject(object);

    auto renderingComponents = scene->getRenderingComponents();
    for (auto renderingComponent : renderingComponents)
    {
        renderer->addObjectToRender(renderingComponent);
    }
}
