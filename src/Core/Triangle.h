#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Rendering/RenderingComponent.h"

namespace Rendering
{
    class TriangleModel: public Rendering::RenderingComponent
    {
    protected:
        std::vector<RenderingComponent::Vertex> loadModel(const char * file) const override
        {
            std::vector<RenderingComponent::Vertex> model;
            model.push_back(RenderingComponent::Vertex(glm::vec3(-0.25, -0.25, 0.0),
                                                       glm::vec4( 1, 0, 0, 1)));
            model.push_back(RenderingComponent::Vertex(glm::vec3( 0.25, -0.25, 0.0),
                                                       glm::vec4( 0, 1, 0, 1)));
            model.push_back(RenderingComponent::Vertex(glm::vec3( 0.25,  0.25, 0.0),
                                                       glm::vec4( 0, 0, 1, 1)));

            return model;
        }
    };
} // end Rendering


#include "GameObject.h"

namespace Core
{
    class Triangle : public GameObject
    {
    public:
        Triangle();
    };
} // end Core

#endif // TRIANGLE_H
