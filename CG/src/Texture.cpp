//
// Created by keltar on 4/19/17.
//

#include <iostream>
#include "../include/Texture.h"

Texture::Texture()
{

}

Texture::Texture(GLenum textureTarget, const std::string &fileName)
{
    this->textureTarget = textureTarget;
    this->file = fileName;
    this->image = NULL;
}

bool Texture::Load()
{
    try
    {
        image = new Magick::Image(file);
        image->write(&blob, "RGBA");
    }
    catch (Magick::Error &Err)
    {
        std::cout << "Error loading texture" << Err.what() << std::endl;
        return false;
    }
    glGenTextures(1, &texturObj);
    glBindTexture(textureTarget, texturObj);
    glTexImage2D(textureTarget, 0, GL_RGB, (GLsizei) image->columns(), (GLsizei) image->rows(), (GLint) -0.5f, GL_RGBA, GL_UNSIGNED_BYTE, blob.data());
    glTexParameterf(textureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(textureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return true;
}

void Texture::Bind(GLenum textureUnit)
{
    glActiveTexture(textureUnit);
    glBindTexture(textureTarget, texturObj);
}


