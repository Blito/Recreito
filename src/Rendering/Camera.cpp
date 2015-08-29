#include "Camera.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include "Shader.h"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Rendering;

void Camera::enable(const Shader * shader)
{
    GLint viewLoc = shader->getUniform("view");

    view = glm::translate(glm::mat4(), position);

    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
}
