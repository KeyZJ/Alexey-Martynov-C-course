#include "square.hpp"

Square::Square(const Point & centre) :
  Shape(centre)
{}

void Square::draw(std::ostream & out) const
{
  out << "SQUARE " << getCentre() << "\n";
}
