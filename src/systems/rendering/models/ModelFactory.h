#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <string>
#include <vector>

#include "Mesh.h"
#include "../Texture.h"

class aiNode;
class aiScene;
class aiMesh;
#include <assimp/material.h>

namespace Rendering
{
    class Model;
    class ModelFactory
    {
    public:
        virtual Model * createModel(const std::string & fileName) const = 0;
    };

    class ASSIMPModelFactory : public ModelFactory
    {
    public:
        Model * createModel(const std::string &fileName) const;
    private:
        void processNode(std::vector<Mesh *> & meshes, aiNode * node, const aiScene * scene) const;
        Mesh * processMesh(const aiMesh * mesh, const aiScene * scene) const;
        std::vector<Texture*> loadTextureFromMaterial(const aiMaterial * material, aiTextureType aiType, Texture::Type type) const;
    };
} // end Rendering

#endif // MODELFACTORY_H
