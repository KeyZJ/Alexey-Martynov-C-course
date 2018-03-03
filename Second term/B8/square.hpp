#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

class Square : public Shape
{
public:
  Square(const Point & centre);
  void draw(std::ostream & out) const override;
};

#endif
