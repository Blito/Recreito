#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

namespace Rendering
{
    class RenderingComponent;
}

namespace Core
{
    class GameObject;

    class Scene
    {
    public:
        Scene();

        std::vector<GameObject*> getGameObjects() const;
        void addGameObject(GameObject * gameObject);


    protected:
        std::vector<GameObject*> gameObjects;
    };
}

#endif // SCENE_H
