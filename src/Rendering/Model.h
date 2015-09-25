#ifndef MODEL_H
#define MODEL_H

#include <vector>

namespace Rendering
{
    class Mesh;
    class Model
    {
    public:
        Model(const std::vector<Mesh*> & meshes);
        ~Model();

        void draw(class Shader * shader) const;

    protected:
        std::vector<Mesh*> meshes;
    };
} // end Rendering

#endif // MODEL_H
