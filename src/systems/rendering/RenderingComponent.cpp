#include "RenderingComponent.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

#include "../../core/GameObject.h"
#include "shaders/ShaderMgr.h"
#include "Renderer.h"
#include "Texture.h"
#include "shaders/Shader.h"
#include "models/Model.h"
#include "models/ModelFactory.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Rendering;

RenderingComponent::RenderingComponent(const Core::GameObject & parent,
                                       const Shader & shaderProgram,
                                       const Mesh * mesh)
    : mesh(mesh),
      shaderProgram(shaderProgram),
      position(parent.position)
{

}

RenderingComponent::~RenderingComponent()
{
}

void RenderingComponent::draw() const
{
    // Send uniform values to GPU
    auto modelMatrix = glm::translate(glm::mat4(1), position);

    GLint modelLoc = shaderProgram.getUniform("model");

    if (modelLoc > -1)
    {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    }

    // Draw the mesh associated with this element
    if (mesh)
    {
        mesh->draw(shaderProgram);
    }
}

Model * RenderingComponent::loadModel(const std::string & file) const
{
    ASSIMPModelFactory modelFactory;
    return modelFactory.createModel(file);
}

const Shader & RenderingComponent::getShaderProgram() const
{
    return shaderProgram;
}
