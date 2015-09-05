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

    model = glm::translate(glm::mat4(1), position);
    model = glm::rotate(model, 0.01f, glm::vec3(1.0f, 1.0f, 0.0f));

    // Update uniforms
    GLint modelLoc = glGetUniformLocation(shaderProgram->id(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

Light::Light(Renderer & renderer)
    : color (1.0f, 1.0f, 1.0f)
{
    renderingComponent = new Rendering::LightModel(*this);
    renderingComponent->init(renderer, "container.jpg");
}

void Light::enable(const Shader * shader)
{
    GLint lightColorLoc = shader->getUniform("lightColor");
    glUniform4f(lightColorLoc, color.x, color.y, color.z, 1.0f);

    GLint lightPosLoc = shader->getUniform("lightPos");
    glUniform3f(lightPosLoc, position.x, position.y, position.z);
}
