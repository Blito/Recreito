#include "Square.h"

using namespace Core;

Square::Square()
{
    renderingComponent = new Rendering::SquareModel();
    renderingComponent->init();
}

