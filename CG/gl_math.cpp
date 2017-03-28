#include "gl_math.h"

Matrix4 EyeMatrix4()
{
    Matrix4 res;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            res[i][j] = 0;
        }
        res[i][i] = 1;
    }

    return res;
}
Matrix4 ZeroMatrix4()
{
    Matrix4 res;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            res[i][j] = 0;
    return res;
}

Vector4 ZeroVector4()
{
    Vector4 res;
    for (int i = 0; i < 4; ++i)
        res[i] = 0;
    return res;
}