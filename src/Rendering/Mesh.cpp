#include "Mesh.h"

#define GLEW_STATIC
#include <GL/glew.h>

using namespace Rendering;

Mesh::Mesh(const std::vector<Vertex> & vertices,
           const std::vector<unsigned int> & indices,
           const std::vector<Texture> & textures)
{
    this->vertices = vertices;
    this->indices = indices;
    this->textures = textures;

    loadToGPU();
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo); // what if multiple where created?
}

void Mesh::draw() const
{
    //TODO: Enable textures

    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Mesh::loadToGPU()
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    // Send vertex data to GPU
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
    //vbos.push_back(vbo);

    // Send indices to GPU
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indices.size(), &indices[0], GL_STATIC_DRAW);


    constexpr unsigned int positionAttrib = 0;
    constexpr unsigned int normalAttrib   = 1;
    constexpr unsigned int textAttrib     = 2;

    // Specify memory structure
    glEnableVertexAttribArray(positionAttrib);
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(normalAttrib);
    glVertexAttribPointer(normalAttrib, 3, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)offsetof(Vertex, normal));
    glEnableVertexAttribArray(textAttrib);
    glVertexAttribPointer(textAttrib, 2, GL_FLOAT, GL_FALSE,
                          sizeof(Vertex), (void*)offsetof(Vertex, texture));

    glBindVertexArray(0);
}
