#include "triangle.hpp"

Triangle::Triangle(const Point & centre) :
  Shape(centre)
{}

void Triangle::draw(std::ostream & out) const
{
  out << "TRIANGLE " << getCentre() << "\n";
}
