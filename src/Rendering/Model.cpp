#include "Model.h"

#include "Mesh.h"

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

void Model::draw() const
{
    for (auto mesh : meshes)
    {
        mesh->draw();
    }
}
