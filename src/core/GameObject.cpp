#include "GameObject.h"

#include "../systems/rendering/models/Model.h"
#include "../systems/rendering/Renderer.h"
#include "../systems/rendering/RenderingComponent.h"
#include "../systems/rendering/shaders/Shader.h"
#include "../systems/behavior/BehaviorSystem.h"

using namespace Core;

void GameObject::addRenderingComponent(Rendering::Renderer & renderer, const Rendering::Shader & shader, const Rendering::Model * model)
{
    this->model = model;
    if (model)
    {
        auto meshes = model->getMeshes();
        for (auto mesh : meshes)
        {
            //auto newComp = renderer.newComponent(*this, shader, mesh);
            renderingComponents.push_back(renderer.newComponent(*this, shader, mesh));
        }
    }
    else
    {
        //auto newComp = renderer.newComponent(*this, shader, nullptr);
        renderingComponents.push_back(renderer.newComponent(*this, shader, nullptr));
    }
}

void GameObject::addBehaviorComponent(Behavior::BehaviorSystem & system, std::function<void()> & behavior)
{
    behaviorComponents.push_back(system.newComponent(behavior));
}
