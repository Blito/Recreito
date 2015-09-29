#include "Scene.h"

#include "GameObject.h"

using namespace Core;

Scene::Scene()
{

}

std::vector<GameObject*> Scene::getGameObjects() const
{
    return gameObjects;
}

void Scene::addGameObject(GameObject * gameObject)
{
    gameObjects.push_back(gameObject);
}

std::vector<Rendering::RenderingComponent*> Scene::getRenderingComponents() const
{
    std::vector<Rendering::RenderingComponent*> renderingComponents;
    for (auto gameObject : gameObjects)
    {
        auto objectRenderingComponents = gameObject->getRenderingComponents();
        renderingComponents.insert(renderingComponents.end(),
                                   objectRenderingComponents.begin(),
                                   objectRenderingComponents.end());
    }
    return renderingComponents;
}
