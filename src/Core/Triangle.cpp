#include "Triangle.h"

using namespace Core;

Triangle::Triangle()
{
    renderingComponent = new Rendering::TriangleModel();
    renderingComponent->init();
}

