#ifndef RENDERINGCOMPONENT_H
#define RENDERINGCOMPONENT_H

#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <glm/mat4x4.hpp>

namespace Core
{
    class GameObject;
}

namespace Rendering
{
    /**
     * @brief The RenderingComponent class is responsible for loading the
     * representation of a renderable object, generating, binding and populating
     * the GPU buffers accordingly.
     */
    class RenderingComponent
    {
    public:
        RenderingComponent(const Core::GameObject & parent,
                           const std::string & shaderProgramName);
        ~RenderingComponent();

        void init(const class Renderer & renderer,
                  const std::string & modelFile);

        /**
         * @brief enable Binds the GPU buffers to this object.
         * @note Does not check correct initialization of the object.
         */
        virtual void enable();

        void draw() const;

        const std::string & getShaderProgram() const;

    protected:
        struct Vertex
        {
            Vertex(glm::vec3 p, glm::vec4 c, glm::vec2 t, glm::vec3 n) :
                position(p), color(c), texture(t), normal(n) {}
            glm::vec3 position;
            glm::vec4 color;
            glm::vec2 texture;
            glm::vec3 normal;
        };

        /**
         * @brief loadModel Loads the model from a file.
         */
        virtual class Model * loadModel(const std::string & file) const;

        unsigned int vertices = 0;

        class Model * model = nullptr;
        class Texture * texture = nullptr;
        const class Shader * shaderProgram = nullptr;

        std::string shaderProgramName;

        const glm::vec3 & position;

        glm::mat4 modelMatrix;

    };

} // end Rendering

#endif // RENDERINGCOMPONENT_H
