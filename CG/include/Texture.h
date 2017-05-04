//
// Created by keltar on 4/19/17.
//

#ifndef CG_TEXTURE_H
#define CG_TEXTURE_H

#include <string>
#include <GL/glew.h>
#include <Magick++.h>

class Texture
{
public:

    Texture(GLenum textureTarget, const std::string &fileName);

    bool Load();
    void Bind(GLenum textureUnit);

private:
    std::string file;
    GLenum textureTarget;
    GLuint texturObj;
    Magick::Image *image;
    Magick::Blob blob;
};


#endif //CG_TEXTURE_H
