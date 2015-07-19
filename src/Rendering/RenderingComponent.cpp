#include "RenderingComponent.h"

#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>

using namespace Rendering;

RenderingComponent::RenderingComponent()
{
}

RenderingComponent::~RenderingComponent()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(vbos.size(), &vbos[0]); // what if multiple where created?
}

void RenderingComponent::init()
{
    auto model = loadModel("");

    vertices = model.size();

    if (vertices > 0)
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

void RenderingComponent::enable() const
{
    glBindVertexArray(vao);
}

void RenderingComponent::draw() const
{
    glBindVertexArray(vao);

    //draw 3 vertices as triangles
    glDrawArrays(GL_TRIANGLE_STRIP, 0, vertices);
}

bool RenderingComponent::loadToGPU(const std::vector<RenderingComponent::Vertex> & model)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(RenderingComponent::Vertex) * vertices, &model[0], GL_STATIC_DRAW);
    vbos.push_back(vbo);

    constexpr unsigned int positionAttrib = 0;
    constexpr unsigned int colorAttrib = 1;
    glEnableVertexAttribArray(positionAttrib);
    glVertexAttribPointer(positionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(RenderingComponent::Vertex), (void*)0);
    glEnableVertexAttribArray(colorAttrib);
    glVertexAttribPointer(colorAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(RenderingComponent::Vertex), (void*)12); // 3 floats * 4 bytes per float

    return true;
}
