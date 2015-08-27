#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/vec3.hpp>

namespace Rendering
{
    class RenderingComponent;
}

namespace Core
{
    class GameObject
    {
    public:
        GameObject();

    //protected:
        Rendering::RenderingComponent * renderingComponent;

        glm::vec3 position, rotation;
    };
} // end Core

#endif // GAMEOBJECT_H
