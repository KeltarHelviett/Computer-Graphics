//
// Created by keltar on 5/11/17.
//

#include "../include/Model.h"

Model::Model()
{

}

Model::Model(Vertex *vs, GLuint *indices, GLenum textureTarget, const std::string &fileName)
{
    this->tex = new Texture(textureTarget, fileName);
    this->Load(vs, indices);
}

void Model::Draw()
{
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);
    this->tex->Bind(GL_TEXTURE0);
    glDrawElements(GL_TRIANGLES, 12 * 3, GL_UNSIGNED_INT, 0);
}

void Model::CalcNormals(GLuint *indices, Vertex *vs)
{
    GLuint indexAmount = sizeof(indices) / sizeof(indices[0]);
    for (GLuint i = 0 ; i < indexAmount; i += 3) {
        GLuint index0 = indices[i];
        GLuint index1 = indices[i + 1];
        GLuint index2 = indices[i + 2];
        Vec3f v1 = vs[index1].pos - vs[index0].pos;
        Vec3f v2 = vs[index2].pos - vs[index0].pos;
        Vec3f Normal = v1.Cross(v2);
        Normal.Normalize();

        vs[index0].normal = vs[index0].normal + Normal;
        vs[index1].normal = vs[index0].normal + Normal;
        vs[index2].normal = vs[index0].normal + Normal;
    }
    GLuint vertexAmount = sizeof(vs) / sizeof(vs[0]);
    for (GLuint i = 0 ; i < vertexAmount; i++) {
        vs[i].normal.Normalize();
    }
}

bool Model::Load(Vertex *vs, GLuint *indices)
{
    if (!tex->Load())
        return false;

    glGenVertexArrays(1, &this->VAO);
    glBindVertexArray(this->VAO);

    this->CalcNormals(indices, vs);

    glGenBuffers(1, &this->VBO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(&vs), vs, GL_STATIC_DRAW);

    glGenBuffers(1, &this->IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(&indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->IBO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);

//    glBindVertexArray(this->VAO);
    return true;
}

