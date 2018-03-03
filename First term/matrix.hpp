#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "shape.hpp"
#include <iostream>
#include <memory>

class Matrix
{
public:
  Matrix(const Shape *shape);
  Matrix(const Matrix & rhs) = default;
  Matrix(Matrix && rhs) = default;
  ~Matrix();
  const Shape** operator[](const size_t & n) const;
  friend std::ostream & operator<<(std::ostream & output, const Matrix & matrix) noexcept;
  Matrix & operator=(const Matrix & rhs) = default;
  Matrix & operator=(Matrix && rhs) = default;
  void addShape(const Shape *shape);
private:
  const Shape ** matrix_;
  size_t colums_;
  size_t lines_;
  bool cross(const Shape * lhs, const Shape * rhs) const noexcept;
};

std::ostream & operator<<(std::ostream & output, const Matrix & matrix) noexcept;
#endif
