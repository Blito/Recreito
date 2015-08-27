#include "Plane.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include "../Rendering/Renderer.h"
#include "../Rendering/Shader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

namespace Rendering
{
    void PlaneModel::enable()
    {
        // Bind VAO and Texture
        RenderingComponent::enable();

        model = glm::rotate(model, 0.01f, glm::vec3(1.0f, 1.0f, 0.0f));
        view = glm::translate(glm::mat4(), glm::vec3(0.0f, 0.0f, -3.0f));
        proj = glm::perspective(45.0f, (GLfloat)800 / (GLfloat)600, 0.1f, 100.0f);

        // Update uniforms
        GLint modelLoc = glGetUniformLocation(shaderProgram->id(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        GLint viewLoc =  glGetUniformLocation(shaderProgram->id(), "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

        GLint projLoc =  glGetUniformLocation(shaderProgram->id(), "projection");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
    }
}

using namespace Core;

Plane::Plane(Rendering::Renderer & renderer)
{
    renderingComponent = new Rendering::PlaneModel(*this);
    renderingComponent->init(renderer, "container.jpg");
}

