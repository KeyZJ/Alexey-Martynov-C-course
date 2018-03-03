#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include "shape.hpp"
#include <memory>

class CompositeShape : public Shape
{
public:
  CompositeShape(Shape* shape);
  CompositeShape(const CompositeShape & rhs) = delete;
  CompositeShape(CompositeShape &&) = delete;
  CompositeShape & operator=(const CompositeShape & rhs) = delete;
  CompositeShape & operator=(CompositeShape &&) = delete;
  Shape& operator[](size_t n) const;
  friend bool operator==(const CompositeShape& cs_lhs, const CompositeShape& cs_rhs);
  friend std::ostream & operator<<(std::ostream & output, const CompositeShape & compositeshape) noexcept;
  size_t getSize() const noexcept;
  double getArea() const noexcept override;
  rectangle_t getFrameRect() const noexcept override;
  void move(const point_t &to_position) noexcept override;
  void move(const double &dx, const double &dy) noexcept override;
  void scale(const double &coefficient) override;
  void rotate(double angle) noexcept override;
  void addShape(Shape* shape);
  void addShape(const CompositeShape &compositeshape) = delete;
  std::string getName() const noexcept;
private:
  std::unique_ptr<Shape*[]> array_;
  size_t arr_size_;
  void print(std::ostream & output) const noexcept override;
};

bool operator==(const CompositeShape& cs_lhs, const CompositeShape& cs_rhs);
std::ostream & operator<<(std::ostream & output, const CompositeShape & compositeshape) noexcept;

#endif
