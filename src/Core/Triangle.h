#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Rendering/RenderingComponent.h"

#include "GameObject.h"

namespace Rendering
{
    class Renderer;
    class TriangleModel: public Rendering::RenderingComponent
    {
    public:
        TriangleModel(const Core::GameObject & parent)
            : RenderingComponent(parent, "Simple") {}

    protected:
        std::vector<RenderingComponent::Vertex> loadModel(const char * file) const override
        {
            std::vector<RenderingComponent::Vertex> model =
            {    /*   position      */  /*   color  */  /*text*/
                {{ -0.25, -0.25, 0.0 }, { 1, 0, 0, 1 }, { 0, 1 }, { 0, 0, 1 }},
                {{  0.25, -0.25, 0.0 }, { 0, 1, 0, 1 }, { 1, 1 }, { 0, 0, 1 }},
                {{  0.25,  0.25, 0.0 }, { 0, 0, 1, 1 }, { 1, 0 }, { 0, 0, 1 }}
            };

            return model;
        }
    };
} // end Rendering

namespace Core
{
    class Triangle : public GameObject
    {
    public:
        Triangle(Rendering::Renderer & renderer);
    };
} // end Core

#endif // TRIANGLE_H
