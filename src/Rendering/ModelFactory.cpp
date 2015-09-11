#include "ModelFactory.h"

#include "Model.h"
#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <iostream>

using namespace Rendering;

Model * ASSIMPModelFactory::createModel(const std::string & fileName) const
{
    // Read from file
    Assimp::Importer importer;
    const aiScene * scene = importer.ReadFile(fileName.c_str(),
                                              aiProcess_Triangulate |
                                              aiProcess_FlipUVs |
                                              aiProcess_GenNormals);

    // Check for errors
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "Error::Assimp: " << importer.GetErrorString() << std::endl;
        return nullptr;
    }

    std::vector<Mesh*> meshes;
    processNode(meshes, scene->mRootNode, scene);

    return new Model(meshes);
}

void ASSIMPModelFactory::processNode(std::vector<Mesh *> & meshes, aiNode * node, const aiScene * scene) const
{
    // Process all the node's meshes
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        const aiMesh * mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene));
    }

    // Repeat for children nodes
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(meshes, node->mChildren[i], scene);
    }
}

Mesh * ASSIMPModelFactory::processMesh(const aiMesh * mesh, const aiScene * scene) const
{
    std::vector<Mesh::Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Mesh::Texture> textures;

    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        glm::vec3 position;
        position.x = mesh->mVertices[i].x;
        position.y = mesh->mVertices[i].y;
        position.z = mesh->mVertices[i].z;

        glm::vec3 normal;
        normal.x = mesh->mNormals[i].x;
        normal.y = mesh->mNormals[i].y;
        normal.z = mesh->mNormals[i].z;

        glm::vec2 textCoord;
        if (mesh->mTextureCoords[0])
        {
            textCoord.x = mesh->mTextureCoords[0][i].x;
            textCoord.y = mesh->mTextureCoords[0][i].y;
        }
        else
        {
            textCoord.x = 0.0f;
            textCoord.y = 0.0f;
        }

        vertices.push_back(Mesh::Vertex(position, normal, textCoord));
    }
}

