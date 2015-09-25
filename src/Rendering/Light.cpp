#include "Light.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include "Shader.h"
#include "Renderer.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Rendering;

void LightModel::enable()
{
    // Bind VAO and Texture
    RenderingComponent::enable();

    modelMatrix = glm::translate(glm::mat4(1), position);
    modelMatrix = glm::rotate(modelMatrix, 0.01f, glm::vec3(1.0f, 1.0f, 0.0f));

    // Update uniforms
    GLint modelLoc = glGetUniformLocation(shaderProgram->id(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(modelMatrix));
}

Light::Light(Renderer & renderer) :
      ambient(0.2f, 0.2f, 0.2f, 1.0f),
      diffuse(0.7f, 0.7f, 0.7f, 1.0f),
      specular(0.1f, 0.1f, 0.1f, 1.0f)
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    renderingComponent = new Rendering::LightModel(*this);
    renderingComponent->init(renderer, "container.jpg");
}

void Light::enable(const Shader * shader)
{
    GLint lightPosLoc = shader->getUniform("lightPos");
    glUniform3f(lightPosLoc, position.x, position.y, position.z);

    GLint ambientLoc = shader->getUniform("light.ambient");
    glUniform4f(ambientLoc, ambient.x, ambient.y, ambient.z, ambient.w);

    GLint diffuseLoc = shader->getUniform("light.diffuse");
    glUniform4f(diffuseLoc, diffuse.x, diffuse.y, diffuse.z, diffuse.w);

    GLint specularLoc = shader->getUniform("light.specular");
    glUniform4f(specularLoc, specular.x, specular.y, specular.z, specular.w);
}
