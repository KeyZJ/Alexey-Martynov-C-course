#include "circle.hpp"

Circle::Circle(const Point & centre) :
  Shape(centre)
{}

void Circle::draw(std::ostream & out) const
{
  out << "CIRCLE " << getCentre() << "\n";
}
