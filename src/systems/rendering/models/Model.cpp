#include "Model.h"

#include "Mesh.h"
#include "../shaders/Shader.h"

using namespace Rendering;

Model::Model(const std::vector<Mesh*> & meshes)
{
    this->meshes = meshes;
}

Model::~Model()
{
    for (auto mesh : meshes)
    {
        delete mesh;
    }
}
