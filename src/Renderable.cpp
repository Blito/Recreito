#include "Renderable.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

using namespace Core;

Renderable::Renderable(const char * modelFile)
{
    if (modelFile == nullptr)
        return;

    auto model = loadModel(modelFile);

    if (!model.empty())
    {
        modelLoaded = true;
        gpuLoaded = loadToGPU(model);
    }

    //TODO: Improve error handling.
    if (!modelLoaded)
        std::cout << "Could not load model." << std::endl;
    if (!gpuLoaded)
        std::cout << "Could not load GPU." << std::endl;
}

Renderable::~Renderable()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(vbos.size(), &vbos[0]); // what if multiple where created?
}

void Renderable::enable() const
{
    glBindVertexArray(vao);
}

bool Renderable::loadToGPU(const std::vector<Renderable::Vertex> & model)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Renderable::Vertex) * 3, &model[0], GL_STATIC_DRAW);
    vbos.push_back(vbo);

    constexpr unsigned int attribNumber = 0;
    glEnableVertexAttribArray(attribNumber);
    glVertexAttribPointer(attribNumber, 3, GL_FLOAT, GL_FALSE, sizeof(Renderable::Vertex), (void*)0);

    return true;
}

std::vector<Renderable::Vertex> Renderable::loadModel(const char * file) const
{
    std::vector<Renderable::Vertex> model;
    model.push_back(Renderable::Vertex(glm::vec3(-0.25, -0.25, 0.0)));
    model.push_back(Renderable::Vertex(glm::vec3( 0.25, -0.25, 0.0)));
    model.push_back(Renderable::Vertex(glm::vec3( 0.25,  0.25, 0.0)));

    return model;
}
