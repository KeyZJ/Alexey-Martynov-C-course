#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const point_t &centre, const double &width, const double &height);
  friend bool operator==(const Rectangle & rect_lhs, const Rectangle & rect_rhs) noexcept;
  friend bool operator!=(const Rectangle & rect_lhs, const Rectangle & rect_rhs) noexcept;
  friend std::ostream & operator<<(std::ostream & output, const Rectangle & rectangle) noexcept;
  double getWidth() const noexcept;
  double getHeight() const noexcept;
  double getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void move(const point_t &to_position) noexcept override;
  void move(const double &dx, const double &dy) noexcept override;
  void scale(const double &coefficient) override;
  void rotate(double angle) noexcept override;
  std::string getName() const noexcept;
private:
  point_t top_left;
  point_t bottom_right;
  void print(std::ostream & output) const noexcept override;
};

bool operator==(const Rectangle & rect_lhs, const Rectangle & rect_rhs) noexcept;
bool operator!=(const Rectangle & rect_lhs, const Rectangle & rect_rhs) noexcept;
std::ostream & operator<<(std::ostream & output, const Rectangle & rectangle) noexcept;

#endif
