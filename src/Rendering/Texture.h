#ifndef TEXTURE_H
#define TEXTURE_H

#define GLEW_STATIC
#include <GL/glew.h>
#include "SOIL.h"

#include <string>

namespace Rendering {

    class Texture
    {
    public:
        Texture(const std::string & filename);

        void enable() const;

    protected:
        GLuint id;
        int width, height;

    private:
        void loadTexture(const std::string & filename);
    };

} // end Rendering

#endif // TEXTURE_H
