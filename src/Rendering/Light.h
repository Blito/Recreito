#ifndef LIGHT_H
#define LIGHT_H

#include "../Core/GameObject.h"
#include "RenderingComponent.h"

#include <glm/vec3.hpp>

namespace Rendering
{
    class LightModel : public Rendering::RenderingComponent
    {
    public:
        LightModel(const Core::GameObject & parent)
            : RenderingComponent(parent, "Light") {}

        void enable() override;
    protected:
        std::vector<RenderingComponent::Vertex> loadModel(const char * file) const override
        {
            std::vector<RenderingComponent::Vertex> model =
            {    /*   position     */  /*   color  */  /*text*/
//                {{ -0.5, -0.5, 0.0 }, { 1, 0, 0, 1 }, { 0, 1 }},
//                {{ -0.5,  0.5, 0.0 }, { 0, 0, 0, 1 }, { 0, 0 }},
//                {{  0.5, -0.5, 0.0 }, { 0, 1, 0, 1 }, { 1, 1 }},
//                {{  0.5,  0.5, 0.0 }, { 0, 0, 1, 1 }, { 1, 0 }}
                 {{-0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},
                 {{ 0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{ 0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{ 0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{-0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{-0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},

                 {{-0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},
                 {{ 0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{ 0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{ 0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{-0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{-0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},

                 {{-0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{-0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{-0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{-0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{-0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},
                 {{-0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},

                 {{ 0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{ 0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{ 0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{ 0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{ 0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},
                 {{ 0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},

                 {{-0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{ 0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{ 0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{ 0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{-0.5f, -0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},
                 {{-0.5f, -0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},

                 {{-0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}},
                 {{ 0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {1.0f, 1.0f}},
                 {{ 0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{ 0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {1.0f, 0.0f}},
                 {{-0.5f,  0.5f,  0.5f}, {1, 1, 1, 1}, {0.0f, 0.0f}},
                 {{-0.5f,  0.5f, -0.5f}, {1, 1, 1, 1}, {0.0f, 1.0f}}
            };

            return model;
        }
    };

    class Light : public Core::GameObject
    {
    public:
        Light(class Renderer & renderer);

        void enable(const class Shader * shader);

        glm::vec3 color;
    };
}

#endif // LIGHT_H
