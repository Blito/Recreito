#include "Camera.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Rendering;

Camera::Camera()
{
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    target = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Camera::enable(const Shader * shader)
{
    GLint viewLoc = shader->getUniform("view");
    view = glm::lookAt(position, target, up);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    GLint viewPosLoc = shader->getUniform("viewPos");
    glUniform3f(viewPosLoc, position.x, position.y, position.z);
}

void Camera::lookAt(float x, float y, float z)
{
    target.x = x; target.y = y; target.z = z;
}
