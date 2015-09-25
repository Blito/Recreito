#include "RenderingComponent.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

#include "../Core/GameObject.h"
#include "../Mgrs/ShaderMgr.h"
#include "Renderer.h"
#include "Texture.h"
#include "Shader.h"
#include "Model.h"
#include "ModelFactory.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace Rendering;

RenderingComponent::RenderingComponent(const Core::GameObject & parent,
                                       const std::string & shaderProgramName)
    : shaderProgramName(shaderProgramName),
      position(parent.position)
{

}

RenderingComponent::~RenderingComponent()
{
    delete model;
}

void RenderingComponent::init(const Renderer & renderer,
                              const std::string & modelFile)
{
    model = loadModel(modelFile);

//    if (!textureFile.empty())
//    {
//        texture = new Texture(textureFile);
//    }

    shaderProgram = renderer.getShaderMgr()->getProgram(shaderProgramName);
}

void RenderingComponent::enable()
{
    modelMatrix = glm::translate(glm::mat4(1), position);

    GLint modelLoc = glGetUniformLocation(shaderProgram->id(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
//    glBindVertexArray(vao);

//    if (texture)
//    {
//        texture->enable();
//    }
//    else
//    {
//        glBindTexture(GL_TEXTURE_2D, 0);
//    }
}

void RenderingComponent::draw() const
{
    if (model)
    {
        model->draw(shaderProgram);
    }
}

Model * RenderingComponent::loadModel(const std::string & file) const
{
    ASSIMPModelFactory modelFactory;
    return modelFactory.createModel(file);
}

const std::string & RenderingComponent::getShaderProgram() const
{
    return shaderProgramName;
}
