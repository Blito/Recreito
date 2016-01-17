#ifndef BEHAVIORCOMPONENT_H
#define BEHAVIORCOMPONENT_H

#include <functional>

namespace Behavior
{

class BehaviorComponent
{
    friend class BehaviorSystem;

public:
    std::function<void()> behavior;

protected:
    BehaviorComponent();
};

} // end Behavior

#endif // BEHAVIORCOMPONENT_H
