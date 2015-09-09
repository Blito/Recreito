#ifndef MESH_H
#define MESH_H

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <vector>

namespace Rendering
{
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

        struct Texture
        {
            unsigned int id;
            enum class Type { DIFFUSE, SPECULAR, OTHER };
        };

        Mesh(const std::vector<Vertex> & vertices,
             const std::vector<unsigned int> & indices,
             const std::vector<Texture> & textures);

        void draw() const;

    protected:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        unsigned int vao, vbo, ebo;

        void loadToGPU();
    };
} // end Rendering

#endif // MESH_H
