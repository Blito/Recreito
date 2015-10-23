#ifndef CAMERA_H
#define CAMERA_H

#include "../core/GameObject.h"

#include <map>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace Rendering
{
    class Shader;

    class Camera : public Core::GameObject
    {
    public:
        Camera();
        void enable(const Shader * shader);

        void lookAt(float x, float y, float z);

    protected:
        glm::vec3 target, up;
        glm::mat4 view;

    private:
        static constexpr const char * viewUniform = "view";
    };

} // end Rendering

#endif // CAMERA_H
