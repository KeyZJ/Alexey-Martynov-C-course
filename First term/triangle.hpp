#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const point_t &A, const point_t &B, const point_t &C);
  friend bool operator==(const Triangle & tri_lhs, const Triangle & tri_rhs) noexcept;
  friend bool operator!=(const Triangle & tri_lhs, const Triangle & tri_rhs) noexcept;
  friend std::ostream & operator<<(std::ostream & output, const Triangle triangle) noexcept;
  double getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void move(const point_t &centre) noexcept override;
  void move(const double &dx, const double &dy) noexcept override;
  void scale(const double &coefficient) override;
  void rotate(double angle) noexcept override;
  void setPoints(const point_t &A, const point_t &B, const point_t &C);
  std::string getName() const noexcept;
private:
  point_t pos_;
  point_t pointA_;
  point_t pointB_;
  point_t pointC_;
  void print(std::ostream & output) const noexcept override;
  static double getMin(const double &A, const double &B, const double &C);
  static double getMax(const double &A, const double &B, const double &C);
};

bool operator==(const Triangle & tri_lhs, const Triangle & tri_rhs) noexcept;
bool operator!=(const Triangle & tri_lhs, const Triangle & tri_rhs) noexcept;
std::ostream & operator<<(std::ostream & output, const Triangle triangle) noexcept;

#endif
