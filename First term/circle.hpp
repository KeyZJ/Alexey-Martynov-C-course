#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape
{
public:
  Circle(const point_t &centre, const double &radius);
  friend bool operator==(const Circle & cir_lhs, const Circle & cir_rhs) noexcept;
  friend bool operator!=(const Circle & cir_lhs, const Circle & cir_rhs) noexcept;
  friend std::ostream & operator<<(std::ostream & output, const Circle & circle) noexcept;
  double getRadius() const noexcept;
  double getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void move(const point_t &to_position) noexcept override;
  void move(const double &dx, const double &dy) noexcept override;
  void scale(const double &coefficient) override;
  void rotate(double /*angle*/) noexcept override;
  void setRadius(const double &radius);
  std::string getName() const noexcept;
private:
  point_t pos_;
  double radius_;
  void print(std::ostream & output) const noexcept override;
};

bool operator==(const Circle & cir_lhs, const Circle & cir_rhs) noexcept;
bool operator!=(const Circle & cir_lhs, const Circle & cir_rhs) noexcept;
std::ostream & operator<<(std::ostream & output, const Circle & circle) noexcept;

#endif
