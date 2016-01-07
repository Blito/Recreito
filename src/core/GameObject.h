#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/vec3.hpp>
#include <vector>
#include <memory>

#include "../systems/rendering/RenderingComponent.h"

namespace Rendering
{
    class RenderingComponent;
    class Renderer;
    class Model;
    class Shader;
}

namespace Core
{
    class GameObject
    {
    public:
        glm::vec3 position, rotation;

        void addRenderingComponent(Rendering::Renderer & renderer, const Rendering::Shader & shader, const Rendering::Model * model);

    protected:
        std::vector<std::unique_ptr<Rendering::RenderingComponent>>  renderingComponents;

        const Rendering::Model * model;
    };
} // end Core

#endif // GAMEOBJECT_H
