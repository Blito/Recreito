#include "BehaviorSystem.h"

#include "BehaviorComponent.h"

using namespace Behavior;

BehaviorSystem::BehaviorSystem()
{

}

void BehaviorSystem::update(float millis)
{
    for (BehaviorComponent * behavior : components)
    {
        behavior->behavior();
    }
}

BehaviorComponent * BehaviorSystem::newComponent(std::function<void()> & behavior)
{
    auto component = new BehaviorComponent();
    component->behavior = behavior;

    components.push_back(component);

    return component;
}
