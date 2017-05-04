//
// Created by keltar on 4/1/17.
//

#include "../include/Point.h"

Point::Point()
{

}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

float Point::Distance(Point &&other)
{
    return sqrtf(powf(x - other.x, 2) + powf(y - other.y, 2));
}
