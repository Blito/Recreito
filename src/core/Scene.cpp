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
