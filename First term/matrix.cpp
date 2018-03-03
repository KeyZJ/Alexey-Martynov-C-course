#include "matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>

Matrix::Matrix(const Shape * shape) :
  matrix_(nullptr),
  colums_(1),
  lines_(1)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Object can't be nullptr!");
  }
  matrix_ = new const Shape *[1];
  matrix_[0] = shape;
}

Matrix::~Matrix()
{
  delete[] matrix_;
}

const Shape ** Matrix::operator[](const size_t & n) const
{
  if (n > lines_)
  {
    throw std::invalid_argument("Out of matrix size");
  }
  return (matrix_ + n * colums_);
}
std::ostream & operator<<(std::ostream & output, const Matrix & matrix) noexcept
{
  for (size_t i = 0; i < matrix.lines_; i++)
  {
    for (size_t j = 0; j < matrix.colums_; j++)
    {
      if (matrix.matrix_[i * matrix.colums_ + j] == nullptr)
      {
        output << "0\t";
      }
      else
      {
        output << matrix.matrix_[i * matrix.colums_ + j]->getName() << '\t';
      }
    }
    std::cout << '\n';
  }
  return output;
}

void Matrix::addShape(const Shape * shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Object can't be nullptr!");
  }
  for (size_t i = 0; i < colums_ * lines_; i++)
  {
    if (matrix_[i] == shape)
    {
      throw std::invalid_argument("Object already in matrix!");
    }
  }
  size_t i = lines_, j = colums_ - 1;
  while ((i != 0) && (!cross(matrix_[(i - 1)*colums_ + j], shape)))
  {
    (j != 0) ? j-- : (i--, j = colums_ - 1);
  }
  if (i == lines_)
  {
    lines_++;
    const Shape ** temp_matrix = new const Shape *[colums_ * lines_];
    i = 0;
    while (i < (lines_ - 1) * colums_)
    {
      temp_matrix[i] = matrix_[i];
      i++;
    }
    temp_matrix[i++] = shape;
    while (i < colums_ * lines_)
    {
      temp_matrix[i++] = nullptr;
    }
    delete[] matrix_;
    matrix_ = temp_matrix;
  }
  else
  {
    j = 0;
    while ((j < colums_) && (matrix_[i * colums_ + j] != nullptr))
    {
      j++;
    }
    if (j == colums_)
    {
      ++colums_;
      const Shape ** temp_matrix = new const Shape *[colums_ * lines_];
      j = 0;
      size_t iter = 0;
      while (j < colums_ * lines_)
      {
        if ((j + 1) % colums_ == 0)
        {
          if ((i + 1) == ((j + 1) / colums_))
          {
            temp_matrix[j] = shape;
          }
          else
          {
            temp_matrix[j] = nullptr;
          }
        }
        else
        {
          temp_matrix[j] = matrix_[iter++];
        }
        j++;
      }
      delete[] matrix_;
      matrix_ = temp_matrix;
    }
    else
    {
      matrix_[i * colums_ + j] = shape;
    }
  }
}

bool Matrix::cross(const Shape * lhs, const Shape * rhs) const noexcept
{
  if ((lhs == nullptr) || (rhs == nullptr))
  {
    return false;
  }
  return ((fabs(lhs->getFrameRect().pos.x - rhs->getFrameRect().pos.x) 
      < ((lhs->getFrameRect().height / 2) + (rhs->getFrameRect().height / 2)))
          && ((fabs(lhs->getFrameRect().pos.y - rhs->getFrameRect().pos.y) 
              < ((lhs->getFrameRect().width / 2) + (rhs->getFrameRect().width / 2)))));
}
