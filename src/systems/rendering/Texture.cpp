#include "Texture.h"

#include <iostream>

using namespace Rendering;

Texture::Texture(const std::string & filename, Type type) :
    type(type)
{
    loadTexture(filename);
}

void Texture::enable() const
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::enable(GLuint textureUnit,
                     GLuint samplerUniformLocation) const
{
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, id);
    glUniform1i(samplerUniformLocation, textureUnit);
}

void Texture::loadTexture(const std::string & filename)
{
    // Load file to array in memory
    std::string aux = "../resources/models/nanosuit/" + filename;
    unsigned char * image = SOIL_load_image(aux.c_str(),
                                            &width, &height, 0,
                                            SOIL_LOAD_RGB);

    if (image == 0)
        std::cout << "Texture could not be loaded." << std::endl;

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

