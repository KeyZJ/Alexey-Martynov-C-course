#define _USE_MATH_DEFINES 
#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

Rectangle::Rectangle(const point_t &centre, const double &width, const double &height) :
  top_left( {centre.x - width / 2, centre.y - height / 2} ),
  bottom_right( {centre.x + width / 2, centre.y + height / 2} )
{
  if (width <= 0 || height <= 0)
  {
    throw std::invalid_argument("Width or height can't be <= 0!");
  }
}

bool operator==(const Rectangle & rect_lhs, const Rectangle & rect_rhs) noexcept
{
  return ((rect_lhs.top_left == rect_rhs.top_left) && (rect_lhs.bottom_right == rect_rhs.bottom_right));
}

bool operator!=(const Rectangle & rect_lhs, const Rectangle & rect_rhs) noexcept
{
  return ((rect_lhs.top_left != rect_rhs.top_left) || (rect_lhs.bottom_right != rect_rhs.bottom_right));
}

std::ostream & operator<<(std::ostream & output, const Rectangle & rectangle) noexcept
{
  rectangle.print(output);
  return output;
}

double Rectangle::getWidth() const noexcept
{
  return fabs((top_left.x - bottom_right.x));
}

double Rectangle::getHeight() const noexcept
{
  return fabs((top_left.y - bottom_right.y));
}

double Rectangle::getArea() const noexcept
{
  return (fabs (bottom_right.x - top_left.x) ) * (fabs (bottom_right.y - top_left.y) );
}

rectangle_t Rectangle::getFrameRect() const noexcept
{
  return { fabs(bottom_right.x - top_left.x), fabs(bottom_right.y - top_left.y),
      { fabs((bottom_right.x - top_left.x)/2), fabs((bottom_right.y - top_left.y)/2)} };
}

void Rectangle::move(const point_t &to_position) noexcept //FIX ME!
{
  point_t centre = Rectangle::getFrameRect().pos;
  Rectangle::move(to_position.x - centre.x, to_position.y - centre.y);
}

void Rectangle::move(const double &dx, const double &dy) noexcept
{
  top_left.x += dx;
  bottom_right.x += dx;
  top_left.y += dy;
  bottom_right.y += dy;
}

void Rectangle::scale(const double &coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be <= 0!");
  }
  point_t centre = Rectangle::getFrameRect().pos;
  top_left = { centre.x + (top_left.x - centre.x) * coefficient, centre.y + (top_left.y - centre.y) * coefficient };
  bottom_right = { centre.x + (bottom_right.x - centre.x) * coefficient, centre.y + (bottom_right.y - centre.y) * coefficient };
}

void Rectangle::rotate(double angle) noexcept
{
  point_t centre = Rectangle::getFrameRect().pos;
  angle = (angle * M_PI) / 180;
  const double sin_a = sin(angle);
  const double cos_a = cos(angle);
  top_left = { centre.x + (top_left.x - centre.x) * cos_a - (top_left.y - centre.y) * sin_a, 
      centre.y + (top_left.y - centre.y) * cos_a - (top_left.x - centre.x) * sin_a };
  bottom_right = { centre.x + (bottom_right.x - centre.x) * cos_a - (bottom_right.y - centre.y) * sin_a, 
      centre.y + (bottom_right.y - centre.y) * cos_a - (bottom_right.x - centre.x) * sin_a };
}

std::string Rectangle::getName() const noexcept
{
  return "Rectangle";
}

void Rectangle::print(std::ostream & output) const noexcept
{
  output << "Rectangle info: " << " (" << top_left << ", " << bottom_right << ")\n";
}
