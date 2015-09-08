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
        model = glm::scale(model, glm::vec3(3.0f, 3.0f, 3.0f));
        model = glm::rotate(model, 0.01f, glm::vec3(1.0f, 1.0f, 0.0f));

        // Update uniforms
        GLint modelLoc = glGetUniformLocation(shaderProgram->id(), "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        GLint ambientLoc = glGetUniformLocation(shaderProgram->id(), "material.ambient");
        glUniform4f(ambientLoc, ambient.x, ambient.y, ambient.z, ambient.w);

        GLint diffuseLoc = glGetUniformLocation(shaderProgram->id(), "material.diffuse");
        glUniform4f(diffuseLoc, diffuse.x, diffuse.y, diffuse.z, diffuse.w);

        GLint specularLoc = glGetUniformLocation(shaderProgram->id(), "material.specular");
        glUniform4f(specularLoc, specular.x, specular.y, specular.z, specular.w);

        GLint shininessLoc = glGetUniformLocation(shaderProgram->id(), "material.shininess");
        glUniform1f(shininessLoc, shininess);
    }
}

using namespace Core;

Cube::Cube(Rendering::Renderer & renderer)
{
    renderingComponent = new Rendering::CubeModel(*this);
    renderingComponent->init(renderer, "container.jpg");
}

