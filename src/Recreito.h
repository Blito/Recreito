#ifndef RECREITO_H
#define RECREITO_H

// Forward refs
namespace Rendering
{
    class Renderer;
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
};

#endif // RECREITO_H
