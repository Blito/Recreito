#ifndef CAMERA_H
#define CAMERA_H

#include "../Core/GameObject.h"

#include <map>
#include <glm/mat4x4.hpp>

namespace Rendering
{
    class Shader;

    class Camera : public Core::GameObject
    {
    public:
        void enable(const Shader * shader);

    protected:
        // Cache: Shader program -> location of view uniform
        std::map<const Shader*, int> shader_viewLoc;

        glm::mat4 view;

    private:
        static constexpr const char * viewUniform = "view";
    };

} // end Rendering

#endif // CAMERA_H
