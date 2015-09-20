#ifndef RECREITO_H
#define RECREITO_H

// Forward refs
namespace Rendering
{
    class Renderer;
}
namespace Core
{
    class GameObject;
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

    Rendering::Renderer * renderer;

    Core::GameObject * object = nullptr;
    Core::GameObject * object2 = nullptr;

private:
    void initScene();

    float magicI = 0.0f;
};

#endif // RECREITO_H
