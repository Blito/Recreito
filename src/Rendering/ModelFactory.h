#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <string>

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
        Model * createModel(const std::string &fileName) const;
    };
} // end Rendering

#endif // MODELFACTORY_H
