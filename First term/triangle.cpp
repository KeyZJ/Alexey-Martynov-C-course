#define _USE_MATH_DEFINES 
#include "triangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

Triangle::Triangle(const point_t &A, const point_t &B, const point_t &C) :
  pointA_(A),
  pointB_(B),
  pointC_(C)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Point of triange must be different!");
  }
}

bool operator==(const Triangle & tri_lhs, const Triangle & tri_rhs) noexcept
{
  return ((tri_lhs.pointA_ == tri_rhs.pointA_) && (tri_lhs.pointB_ == tri_rhs.pointB_) && (tri_lhs.pointC_ == tri_rhs.pointC_));
}

bool operator!=(const Triangle & tri_lhs, const Triangle & tri_rhs) noexcept
{
  return ((tri_lhs.pointA_ != tri_rhs.pointA_) || (tri_lhs.pointB_ != tri_rhs.pointB_) || (tri_lhs.pointC_ != tri_rhs.pointC_));
}

std::ostream & operator<<(std::ostream & output, const Triangle triangle) noexcept
{
  triangle.print(output);
  return output;
}

double Triangle::getMin(const double &A, const double &B, const double &C)
{
  double min = A;
  if (B < min)
  {
    min = B;
  }
  if (C < min)
  {
    min = C;
  }
  return min;
}

double Triangle::getMax(const double &A, const double &B, const double &C)
{
  double max = A;
  if (B > max)
  {
    max = B;
  }
  if (C > max)
  {
    max = C;
  }
  return max;
}

double Triangle::getArea() const noexcept
{
  return ((fabs(((pointA_.x - pointC_.x) * (pointB_.y - pointC_.y)) - ((pointA_.y - pointC_.y) * (pointB_.x - pointC_.x))) / 2));
}

rectangle_t Triangle::getFrameRect() const noexcept
{
  double max_x = getMax(pointA_.x, pointB_.x, pointC_.x);
  double min_x = getMin(pointA_.x, pointB_.x, pointC_.x);
  double max_y = getMax(pointA_.y, pointB_.y, pointC_.y);
  double min_y = getMin(pointA_.y, pointB_.y, pointC_.y);
  return { max_x - min_x, max_y - min_y, { (pointA_.x + pointB_.x + pointC_.x) / 3 , (pointA_.y + pointB_.y + pointC_.y) / 3 } };
}

void Triangle::move(const point_t &to_position) noexcept
{
  point_t centre = Triangle::getFrameRect().pos;
  pointA_.x += to_position.x - centre.x;
  pointB_.x += to_position.x - centre.x;
  pointC_.x += to_position.x - centre.x;
  pointA_.y += to_position.y - centre.y;
  pointB_.y += to_position.y - centre.y;
  pointC_.y += to_position.y - centre.y;
  centre = to_position;
}

void Triangle::move(const double &dx, const double &dy) noexcept
{
  point_t centre = Triangle::getFrameRect().pos;
  centre.x += dx;
  pointA_.x += dx;
  pointB_.x += dx;
  pointC_.x += dx;
  centre.y += dy;
  pointA_.y += dy;
  pointB_.y += dy;
  pointC_.y += dy;
}

void Triangle::scale(const double &coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be <= 0!");
  }
  point_t centre = Triangle::getFrameRect().pos;
  pointA_ = { centre.x + (pointA_.x - centre.x) * coefficient, centre.y + (pointA_.y - centre.y) * coefficient };
  pointB_ = { centre.x + (pointB_.x - centre.x) * coefficient, centre.y + (pointB_.y - centre.y) * coefficient };
  pointC_ = { centre.x + (pointC_.x - centre.x) * coefficient, centre.y + (pointC_.y - centre.y) * coefficient };
}

void Triangle::rotate(double angle) noexcept
{
  point_t centre = Triangle::getFrameRect().pos;
  angle = (angle * M_PI) / 180;
  const double sin_a = sin(angle);
  const double cos_a = cos(angle);
  pointA_ = { centre.x + (pointA_.x - centre.x) * cos_a - (pointA_.y - centre.y) * sin_a,
      centre.y + (pointA_.y - centre.y) * cos_a + (pointA_.x - centre.x) * sin_a };
  pointB_ = { centre.x + (pointB_.x - centre.x) * cos_a - (pointB_.y - centre.y) * sin_a,
      centre.y + (pointB_.y - centre.y) * cos_a + (pointB_.x - centre.x) * sin_a };
  pointC_ = { centre.x + (pointC_.x - centre.x) * cos_a - (pointC_.y - centre.y) * sin_a,
      centre.y + (pointC_.y - centre.y) * cos_a + (pointC_.x - centre.x) * sin_a };
}

void Triangle::setPoints(const point_t &A, const point_t &B, const point_t &C)
{
  if (getArea() == 0)
  {
    throw std::invalid_argument("Points of triangle must be different!");
  }
  pointA_ = A;
  pointB_ = B;
  pointC_ = C;
}

std::string Triangle::getName() const noexcept
{
  return "Triangle";
}

void Triangle::print(std::ostream & output) const noexcept
{
  output << "Triangle info: " << "( " << pointA_ << ", " << pointB_ << ", " << pointC_ << ")\n";
}
