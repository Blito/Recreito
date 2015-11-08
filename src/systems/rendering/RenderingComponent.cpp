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


Model * RenderingComponent::loadModel(const std::string & file) const
{
    ASSIMPModelFactory modelFactory;
    return modelFactory.createModel(file);
}
