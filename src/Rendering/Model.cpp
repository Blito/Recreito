#include "Model.h"

#include "Mesh.h"
#include "Shader.h"

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

void Model::draw(Shader * shader) const
{
    for (auto mesh : meshes)
    {
        mesh->draw(shader);
    }
}
