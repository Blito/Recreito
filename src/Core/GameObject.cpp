#include "GameObject.h"

#include "../Rendering/Model.h"
#include "../Rendering/RenderingComponent.h"
#include "../Rendering/Shader.h"

using namespace Core;

GameObject::GameObject(const Rendering::Shader * shader, const Rendering::Model * model) :
    model(model)
{
    if (shader)
    {
        if (model)
        {
            auto meshes = model->getMeshes();
            for (auto mesh : meshes)
            {
                 renderingComponents.push_back(new Rendering::RenderingComponent(*this, *shader, mesh));
            }
        }
        else
        {
            renderingComponents.push_back(new Rendering::RenderingComponent(*this, *shader, nullptr));
        }
    }
}

std::vector<Rendering::RenderingComponent*> GameObject::getRenderingComponents() const
{
    return renderingComponents;
}
