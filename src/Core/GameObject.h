#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

namespace Rendering
{
    class RenderingComponent;
}

namespace Core
{
    class GameObject
    {
    public:
        GameObject();

    //protected:
        Rendering::RenderingComponent * renderingComponent;
    };
} // end Core

#endif // GAMEOBJECT_H
