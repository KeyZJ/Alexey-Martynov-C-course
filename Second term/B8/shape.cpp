#include "shape.hpp"

Shape::Shape(const Point & centre) :
  centre_(centre)
{}

Shape::~Shape()
{}

int Shape::getCentreX() const
{
  return centre_.x;
}

int Shape::getCentreY() const
{
  return centre_.y;
}

Point Shape::getCentre() const
{
  return centre_;
}

bool Shape::isMoreLeft(std::shared_ptr<Shape> rhs) const
{
  return (getCentreX() < rhs->getCentreX());
}

bool Shape::isUpper(std::shared_ptr<Shape> rhs) const
{
  return (getCentreY() > rhs->getCentreY());
}
