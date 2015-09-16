#include "RenderingComponent.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

#include "../Core/GameObject.h"
#include "../Mgrs/ShaderMgr.h"
#include "Renderer.h"
#include "Texture.h"
#include "Model.h"
#include "ModelFactory.h"

#include <glm/gtc/matrix_transform.hpp>

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
        model->draw();
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
