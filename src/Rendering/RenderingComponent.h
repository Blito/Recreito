#ifndef RENDERINGCOMPONENT_H
#define RENDERINGCOMPONENT_H

#include <string>
#include <vector>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Rendering {

    /**
     * @brief The RenderingComponent class is responsible for loading the
     * representation of a renderable object, generating, binding and populating
     * the GPU buffers accordingly.
     */
    class RenderingComponent
    {
    public:
        RenderingComponent();
        ~RenderingComponent();

        void init(const std::string & textureFile);

        /**
         * @brief enable Binds the GPU buffers to this object.
         * @note Does not check correct initialization of the object.
         */
        void enable() const;

        void draw() const;

    protected:

        struct Vertex
        {
            Vertex(glm::vec3 p, glm::vec4 c, glm::vec2 t) :
                position(p), color(c), texture(t) {}
            glm::vec3 position;
            glm::vec4 color;
            glm::vec2 texture;
        };

        /**
         * @brief loadToGPU Creates buffers and binds the model to them.
         * @param model The created model.
         * @return true if load was successful.
         * @sa loadModel
         */
        bool loadToGPU(const std::vector<Vertex> & model);

        /**
         * @brief loadModel Loads the model from a file.
         */
        virtual std::vector<Vertex> loadModel(const char * file) const = 0;

        unsigned int vao;
        std::vector<unsigned int> vbos;
        unsigned int vertices = 0;
        bool modelLoaded = false;
        bool gpuLoaded = false;

        class Texture * texture = nullptr;

    };

} // end Rendering

#endif // RENDERINGCOMPONENT_H
