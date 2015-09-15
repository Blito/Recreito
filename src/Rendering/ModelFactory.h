#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <string>
#include <vector>

#include "Mesh.h"

class aiNode;
class aiScene;
class aiMesh;
class aiMaterial;

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
        std::vector<Mesh::Texture> loadTextureFromMaterial(const aiMaterial * material, int type, Mesh::Texture::Type) const;
    };
} // end Rendering

#endif // MODELFACTORY_H
