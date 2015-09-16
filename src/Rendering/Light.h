#ifndef LIGHT_H
#define LIGHT_H

#include "../Core/GameObject.h"
#include "RenderingComponent.h"

#include <glm/vec4.hpp>

#include "Model.h"

namespace Rendering
{
    class LightModel : public Rendering::RenderingComponent
    {
    public:
        LightModel(const Core::GameObject & parent)
            : RenderingComponent(parent, "Light") {}

        void enable() override;
    protected:
        Model * loadModel(const std::string & file) const override
        {
            return nullptr;
        }
    };

    class Light : public Core::GameObject
    {
    public:
        Light(class Renderer & renderer);

        void enable(const class Shader * shader);

        glm::vec4 color, ambient, diffuse, specular;
    };
}

#endif // LIGHT_H
