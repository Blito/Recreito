#include "Square.h"

#include "../Rendering/Renderer.h"

using namespace Core;

Square::Square(Rendering::Renderer & renderer)
{
    renderingComponent = new Rendering::SquareModel(*this);
    renderingComponent->init(renderer, "container.jpg");
}

