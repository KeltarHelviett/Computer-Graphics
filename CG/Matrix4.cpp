//
// Created by keltar on 3/22/17.
//

#include "Matrix4.h"

Matrix4::Matrix4()
{

}

Matrix4::Matrix4(std::initializer_list<std::initializer_list<float>> mat)
{
    int i, j;
    std::initializer_list<std::initializer_list<float>>::iterator it;
    std::initializer_list<float>::iterator jt;
    for (i = 0, it = mat.begin(); i < 4; ++i, ++it)
    {
        for (j = 0, jt = it->begin(); j < 4; ++j, ++jt)
        {
            _mat[i][j] = *jt;
        }
    }
}

Matrix4 Matrix4::Mult(Matrix4 &other)
{
    Matrix4 res;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            res._mat[i][j] = 0;
            for (int r = 0; r < 4; ++r)
            {
                res._mat[i][j] += this->_mat[i][r] * other._mat[r][j];
            }
        }
    }
    return res;
}

Matrix4 Matrix4::operator*(Matrix4 &other)
{
    return this->Mult(other);
}

Matrix4 Matrix4::Add(Matrix4 &other)
{
    Matrix4 res;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res._mat[i][j] = this->_mat[i][j] + other._mat[i][j];
        }
    }
    return res;
}


Vector4 Matrix4::Mult(Vector4 &other)
{
    Vector4 res;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            res[i] += _mat[i][j] * other[j];
        }
    }
    return res;
}

Vector4 Matrix4::operator*(Vector4 &other)
{
    return this->Mult(other);
}

float *Matrix4::operator[](unsigned int index)
{
    return &_mat[0][0] + index * 4;
}



