//
// Created by keltar on 3/23/17.
//

#ifndef CG_GL_MATH_H
#define CG_GL_MATH_H

#include "Matrix4.h"
#include "Vector.h"
#include "Quaternion.h"

#define ToRadian(x) (float)((x) * M_PI / 180.0f)
#define ToDegree(x) ((x) * 180.0f / M_PI)

Matrix4 EyeMatrix4();
Matrix4 ZeroMatrix4();

#endif //CG_GL_MATH_H
