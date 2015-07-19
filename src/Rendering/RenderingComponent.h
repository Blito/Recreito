#ifndef RENDERINGCOMPONENT_H
#define RENDERINGCOMPONENT_H

#include <vector>
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

        void init();

        /**
         * @brief enable Binds the GPU buffers to this object.
         * @note Does not check correct initialization of the object.
         */
        void enable() const;

        void draw() const;

    protected:

        struct Vertex
        {
            Vertex(glm::vec3 p, glm::vec4 c) : position(p), color(c) {}
            glm::vec3 position;
            glm::vec4 color;
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

    };

} // end Rendering

#endif // RENDERINGCOMPONENT_H
