//
// Created by keltar on 5/11/17.
//

#include <iostream>
#include "../include/Model.h"

Model::Model()
{
    VAO = VBO = IBO = 0;
    x = y = z = 0;
}

Model::Model(Vertex *vs, GLuint *indices, GLuint vertexCount, GLuint indCount, GLenum textureTarget, const std::string &fileName)
{
    VAO = VBO = IBO = 0;
    this->tex = new Texture(textureTarget, fileName);
    this->Load(vs, indices, vertexCount, indCount);
}

void Model::Draw()
{
    glBindVertexArray(VAO);
    tex->Bind(GL_TEXTURE0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

void Model::CalcNormals(GLuint *indices, Vertex *vs, GLuint vertexCount, GLuint indexCount)
{
    std::cout << "IN" << std::endl;
    for (GLuint i = 0 ; i < indexCount; i += 3) {
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
    for (GLuint i = 0 ; i < vertexCount; i++) {
        vs[i].normal.Normalize();
        std::cout << vs[i].normal[0] << vs[i].normal[1] << vs[i].normal[2] << std::endl;
    }
}

bool Model::Load(Vertex *vs, GLuint *indices, GLuint vertexCount, GLuint indCount)
{
    if (!tex->Load())
        return false;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    this->CalcNormals(indices, vs, vertexCount, indCount);
    this->indexCount = indCount;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(*vs), vs, GL_STATIC_DRAW);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indCount * sizeof(*indices), indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);

    glBindVertexArray(VAO);
    return true;
}

Matrix4 Model::SetPosition(GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x; this->y = y; this->z = z;
    return
            {
                {1.0f, 0.0f, 0.0f, x},
                {0.0f, 1.0f, 0.0f, y},
                {0.0f, 0.0f, 1.0f, z},
                {0.0f, 0.0f, 0.0f, 1.0f}
            }
    ;

}

Matrix4 Model::GetTrans()
{
    return this->SetPosition(x, y, z);
}

Model::~Model()
{
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &IBO);
    glDeleteVertexArrays(1, &VAO);
}

