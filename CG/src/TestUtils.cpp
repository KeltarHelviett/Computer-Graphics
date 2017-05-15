//
// Created by keltar on 5/15/17.
//
#include "../include/TestUtils.h"

std::ostream &operator<<(std::ostream &out, Vec3f v)
{
    out << '(' << v[0] << ", " << v[1] << ", " << v[2] << ')' << std::endl;
    return out;
}