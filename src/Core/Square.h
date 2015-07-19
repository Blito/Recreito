#ifndef SQUARE_H
#define SQUARE_H

#include "../Rendering/RenderingComponent.h"

namespace Rendering
{
    class SquareModel: public Rendering::RenderingComponent
    {
    protected:
        std::vector<RenderingComponent::Vertex> loadModel(const char * file) const override
        {
            std::vector<RenderingComponent::Vertex> model;
            model.push_back(RenderingComponent::Vertex(glm::vec3(-0.25, 0.5, 0.0),//pos
                                         glm::vec4( 1, 0, 0, 1)));   //color
            model.push_back(RenderingComponent::Vertex(glm::vec3(-0.25, 0.75, 0.0),//pos
                                         glm::vec4( 0, 0, 0, 1)));   //color
            model.push_back(RenderingComponent::Vertex(glm::vec3(0.25, 0.5, 0.0),  //pos
                                         glm::vec4( 0, 1, 0, 1)));   //color
            //4th vertex
            model.push_back(RenderingComponent::Vertex(glm::vec3(0.25, 0.75, 0.0),//pos
                                         glm::vec4(0, 0, 1, 1)));   //color

            return model;
        }
    };
} // end Rendering


#include "GameObject.h"

namespace Core
{
    class Square : public GameObject
    {
    public:
        Square();
    };
} // end Core

#endif // SQUARE_H
