//
// Created by keltar on 5/11/17.
//

#ifndef CG_MODEL_H
#define CG_MODEL_H



#include "Texture.h"
#include "Vector.h"
#include "Matrix4.h"

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

    Matrix4 SetPosition(GLfloat x, GLfloat y, GLfloat z);
    Matrix4 GetTrans();

    ~Model();
private:
    GLfloat x, y, z;
    void CalcNormals(GLuint *indices, Vertex* vs, GLuint vertexCount, GLuint indexCount);
    GLuint VAO, VBO, IBO;
    Texture *tex;
    GLuint indexCount;

};


#endif //CG_MODEL_H
