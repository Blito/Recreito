#include "Texture.h"

using namespace Rendering;

Texture::Texture(const std::string & filename)
{
    loadTexture(filename);
}

void Texture::enable() const
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::loadTexture(const std::string & filename)
{
    // Load file to array in memory
    unsigned char * image = SOIL_load_image(filename.c_str(),
                                            &width, &height, 0,
                                            SOIL_LOAD_RGB);

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    // Set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load array from main memory to GPU
    glTexImage2D(GL_TEXTURE_2D, // texture target
                 0, // mipmap
                 GL_RGB, // format to store the texture
                 width, height,
                 0, // legacy
                 GL_RGB, GL_UNSIGNED_BYTE, // datatype of the source image
                 image);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Free array from memory
    SOIL_free_image_data(image);

    // Unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

