//
// Created by keltar on 4/1/17.
//

#ifndef CG_POINT_H
#define CG_POINT_H

#include "cmath"

struct Point
{
    float x, y;
    Point();
    Point(int x, int y);

    float Distance(Point &&other);
};

float Distance(Point &&p1, Point &&p2);

#endif //CG_POINT_H
