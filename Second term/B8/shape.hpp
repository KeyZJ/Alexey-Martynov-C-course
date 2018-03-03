#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Point.hpp"

#include <memory>
#include <iosfwd>

class Shape
{
public:
  Shape(const Point & centre);
  virtual ~Shape();
  virtual void draw(std::ostream & out) const = 0;
  int getCentreX() const;
  int getCentreY() const;
  Point getCentre() const;
  bool isMoreLeft(std::shared_ptr<Shape> shape) const;
  bool isUpper(std::shared_ptr<Shape> shape) const;
private:
  Point centre_;
};

#endif
