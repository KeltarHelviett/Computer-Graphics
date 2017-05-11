//
// Created by keltar on 5/11/17.
//

#ifndef CG_MODEL_H
#define CG_MODEL_H



#include "Texture.h"
#include "Vector.h"

struct Vertex
{
    Vec3f pos;
    Vec2f tex;
    Vec3f normal;

    Vertex() {}

    Vertex(const Vec3f &pos, const Vec2f &tex)
    {
        this->pos = pos;
        this->tex = tex;
        normal    = {0.0f, 0.0f, 0.0f};
    }
};

class Model
{
public:
    Model();
    Model(Vertex *vs, GLuint *indices, GLuint vertexCount, GLuint indCount, GLenum textureTarget, const std::string &fileName);

    bool Load(Vertex *vs, GLuint *indices, GLuint vertexCount, GLuint indCount);
    void Draw();

private:
    void CalcNormals(GLuint *indices, Vertex* vs);
    GLuint VAO, VBO, IBO;
    Texture *tex;

};


#endif //CG_MODEL_H
