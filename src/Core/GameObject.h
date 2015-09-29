#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/vec3.hpp>
#include <vector>

namespace Rendering
{
    class RenderingComponent;
    class Model;
    class Shader;
}

namespace Core
{
    class GameObject
    {
    public:
        GameObject(const Rendering::Shader * shader, const Rendering::Model * model = nullptr);

        std::vector<Rendering::RenderingComponent*> getRenderingComponents() const;

        glm::vec3 position, rotation;

    protected:
        std::vector<Rendering::RenderingComponent*>  renderingComponents;

        const Rendering::Model * model;
    };
} // end Core

#endif // GAMEOBJECT_H
