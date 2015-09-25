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
        enum class Type { DIFFUSE, SPECULAR };

        /**
         * @brief Texture Loads a texture from file.
         * Automatically loads it into the GPU. To use it, call enable() first.
         */
        Texture(const std::string & filename, Type type);

        /**
         * @brief enable Binds the texture, to be used by the default sampler
         * in the active fragment shader.
         */
        void enable() const;

        /**
         * @brief enable Binds the texture using the given texture unit and
         * uniform sampler name.
         * @param textureUnit Number of the texture unit.
         * @param samplerUniformLocation Location of the sampler.
         *        See glUniformLocation(activeProgramId, samplerUniformName)
         */
        void enable(GLuint textureUnit,
                    GLuint samplerUniformLocation) const;

        Type getType() const { return type; }

    protected:
        GLuint id;
        Type type;
        int width = 0, height = 0;

    private:
        void loadTexture(const std::string & filename);
    };

} // end Rendering

#endif // TEXTURE_H
