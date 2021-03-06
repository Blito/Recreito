#ifndef RECREITO_H
#define RECREITO_H

// Forward refs
namespace Rendering
{
    class Renderer;
}
namespace Core
{
    class Scene;
    class GameObject;
    class InputManager;
}
namespace Behavior
{
    class BehaviorSystem;
}

/**
 * @brief The Recreito class is the starting point for any application.
 */
class Recreito
{
public:
    Recreito();
    ~Recreito();

    void run();

protected:
    bool init ();
    bool shutdown();

    bool initialized = false;
    bool deinitialized = false;

    Core::Scene * scene = nullptr;

    // Update these every loop
    Core::InputManager * inputManager = nullptr;
    Rendering::Renderer * renderer = nullptr;
    Behavior::BehaviorSystem * behaviorSystem = nullptr;

private:
    void initScene();

    float magicI = 0.0f;
};

#endif // RECREITO_H
