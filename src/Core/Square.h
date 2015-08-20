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
            std::vector<RenderingComponent::Vertex> model =
            {    /*   position     */  /*   color  */  /*text*/
                {{ -0.25,  0.5, 0.0 }, { 1, 0, 0, 1 }, { 0, 1 }},
                {{ -0.25, 0.75, 0.0 }, { 0, 0, 0, 1 }, { 0, 0 }},
                {{  0.25,  0.5, 0.0 }, { 0, 1, 0, 1 }, { 1, 1 }},
                {{  0.25, 0.75, 0.0 }, { 0, 0, 1, 1 }, { 1, 0 }}
            };

            return model;
        }
    };
} // end Rendering


#include "GameObject.h"
#include "../Rendering/Texture.h"

namespace Core
{
    class Square : public GameObject
    {
    public:
        Square();
    };
} // end Core

#endif // SQUARE_H
