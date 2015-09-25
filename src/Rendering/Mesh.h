#ifndef MESH_H
#define MESH_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <vector>

namespace Rendering
{
    class Texture;
    class Shader;
    class Mesh
    {
    public:
        struct Vertex
        {
            Vertex(glm::vec3 p, glm::vec3 n, glm::vec2 t) :
                position(p), normal(n), texture(t) {}
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec2 texture;
        };

        Mesh(const std::vector<Vertex> & vertices,
             const std::vector<unsigned int> & indices,
             const std::vector<Texture*> & textures);
        virtual ~Mesh();

        void draw(const Shader * shader) const;

    protected:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture*> textures; //< For now, the Mesh is responsible for deleting these objects

        unsigned int vao, vbo, ebo;

        void loadToGPU();
    };
} // end Rendering

#endif // MESH_H
