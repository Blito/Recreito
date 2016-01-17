#ifndef BEHAVIORSYSTEM_H
#define BEHAVIORSYSTEM_H

#include <vector>
#include <memory>
#include <functional>

namespace Behavior
{

    class BehaviorComponent;

    /**
     * @brief The BehaviorSystem allows game objects to execute actions that are
     * not specific to other systems. This system is the main way to add custom
     * behaviors to specific actors.
     */
    class BehaviorSystem
    {
    public:
        BehaviorSystem();

        void update(float millis);

        BehaviorComponent * newComponent(std::function<void()> & behavior);

    protected:
        std::vector<BehaviorComponent*> components;
    };

} // end Behavior

#endif // BEHAVIORSYSTEM_H
