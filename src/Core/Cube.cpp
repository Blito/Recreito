#include "Cube.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include "../Rendering/Renderer.h"
#include "../Rendering/Shader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

namespace Rendering
{
    void CubeModel::enable()
    {
        // Bind VAO and Texture
        RenderingComponent::enable();

        model = glm::translate(glm::mat4(1), position);
        model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
        model = glm::rotate(model, 0.01f, glm::vec3(1.0f, 1.0f, 0.0f));

        // Update uniforms
        GLint modelLoc = glGetUniformLocation(shaderProgram->id(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    }
}

using namespace Core;

Cube::Cube(Rendering::Renderer & renderer)
{
    renderingComponent = new Rendering::CubeModel(*this);
    renderingComponent->init(renderer, "container.jpg");
}

