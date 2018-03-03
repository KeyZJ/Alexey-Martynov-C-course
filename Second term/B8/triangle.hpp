#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const Point & centre);
  void draw(std::ostream & out) const override;
};

#endif
