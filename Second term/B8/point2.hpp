#ifndef POINT2_HPP
#define POINT2_HPP

#include "shape.hpp"
#include <memory>
#include <iostream>

std::istream & operator>>(std::istream & in, std::shared_ptr<Shape> & shape);
void doPoint2();

#endif
