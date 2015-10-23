#ifndef LIGHT_H
#define LIGHT_H

#include "../../core/GameObject.h"
#include "RenderingComponent.h"

#include <glm/vec4.hpp>

#include "models/Model.h"

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

        // Attenuation properties
        float constant, linear, quadratic;
    };
}

#endif // LIGHT_H
