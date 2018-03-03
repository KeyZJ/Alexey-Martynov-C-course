#define _USE_MATH_DEFINES 
#include "circle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

Circle::Circle(const point_t &centre, const double &radius) :
  pos_(centre),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius can't be <= 0 !");
  }
}

bool operator==(const Circle & cir_lhs, const Circle & cir_rhs) noexcept
{
  return ((cir_lhs.pos_ == cir_rhs.pos_) && (cir_lhs.radius_ == cir_rhs.radius_));
}

bool operator!=(const Circle & cir_lhs, const Circle & cir_rhs) noexcept
{
  return ((cir_lhs.pos_ != cir_rhs.pos_) || (cir_lhs.radius_ != cir_rhs.radius_));
}

std::ostream & operator<<(std::ostream & output, const Circle & circle) noexcept
{
  circle.print(output);
  return output;
}

double Circle::getRadius() const noexcept
{
  return radius_;
}

double Circle::getArea() const noexcept
{
  return radius_ * radius_ * M_PI;
}

rectangle_t Circle::getFrameRect() const noexcept
{
  return { radius_, radius_, pos_ };
}

void Circle::move(const point_t &to_position) noexcept
{
  pos_ = to_position;
}

void Circle::move(const double &dx, const double &dy) noexcept
{
  pos_.x += dx;
  pos_.y += dy;
}

void Circle::scale(const double &coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be <= 0!");
  }
  radius_ *= coefficient;
}

void Circle::rotate(double /*angle*/) noexcept
{

}

void Circle::setRadius(const double &radius)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Radius can't be <= 0!");
  }
  radius_ = radius;
}

std::string Circle::getName() const noexcept
{
  return "Circle";
}

void Circle::print(std::ostream & output) const noexcept
{
  output << "Circle info: " << "( " << pos_ << ", " << radius_ << ")\n";
}
