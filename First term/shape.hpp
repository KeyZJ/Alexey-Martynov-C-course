#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &to_position) = 0;
  virtual void move(const double &dx, const double &dy) = 0;
  virtual void scale(const double &coefficient) = 0;
  virtual void rotate(double angle) = 0;
  virtual std::string getName() const = 0;
  virtual void print(std::ostream & output) const = 0;
};
#endif
