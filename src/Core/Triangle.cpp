#include "Triangle.h"

#include "../Rendering/Renderer.h"

using namespace Core;

Triangle::Triangle(Rendering::Renderer & renderer)
{
    renderingComponent = new Rendering::TriangleModel(*this);
    renderingComponent->init(renderer, "");
}

