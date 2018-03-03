#ifndef POINT2_HPP
#define POINT2_HPP

#include "Point.hpp"

#include <vector>
#include <iosfwd>

using Shape = std::vector<Point>;

std::ostream & operator<<(std::ostream & out, const Shape & shape);
bool isTriangle(const Shape & shape);
bool isRectangle(const Shape & shape);
bool isSquare(const Shape & shape);
void read(std::vector<Shape> & shapes);
void doSecondTask();

#endif
