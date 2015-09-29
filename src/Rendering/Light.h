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
        LightModel(const Core::GameObject & parent,
                   const Shader & shaderProgram);

        virtual void draw() const override;
    };

    class Light : public Core::GameObject
    {
    public:
        Light(const Rendering::Shader * shader,
              const Rendering::Model * model = nullptr);

        void enable(const class Shader * shader);

        glm::vec4 ambient, diffuse, specular;
    };
}

#endif // LIGHT_H
