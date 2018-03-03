#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const Point & centre);
  void draw(std::ostream & out) const override;
};

#endif
