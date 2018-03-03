#define _USE_MATH_DEFINES 
#include "compositeshape.hpp"
#include <iostream>
#include <stdexcept>
#include <memory>
#include <cmath>
#include <algorithm>

CompositeShape::CompositeShape(Shape * shape) :
  array_(new Shape*[1]),
  arr_size_(1)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Object can't be nullptr!");
  }
  array_[0] = shape;
}

Shape& CompositeShape::operator[](size_t n) const
{
  if (n >= arr_size_)
  {
    throw std::invalid_argument("Out of array range!");
  }
  return *(array_[n]);
}

bool operator==(const CompositeShape& cs_lhs, const CompositeShape& cs_rhs)
{
  bool status = false;
  if (cs_lhs.getSize() == cs_rhs.getSize())
  {
    for (size_t i = cs_lhs.getSize() - 1; i>0; i--)
    {
      if (cs_lhs.array_[i] == cs_rhs.array_[i])
      {
        status = true;
      }
      else
      {
        status = false;
      }
    }
    return status;
  }
  return false;
}

std::ostream & operator<<(std::ostream & output, const CompositeShape & compositeshape) noexcept
{
  compositeshape.print(output);
  return output;
}

size_t CompositeShape::getSize() const noexcept
{
  return arr_size_;
}

double CompositeShape::getArea() const noexcept
{
  double area = array_[0]->getArea();
  for (size_t i = 1; i < arr_size_; i++)
  {
    area += array_[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const noexcept
{
  rectangle_t rect = array_[0]->getFrameRect();
  double minX = rect.pos.x - rect.width / 2;
  double maxX = rect.pos.x + rect.width / 2;
  double minY = rect.pos.y - rect.height / 2;
  double maxY = rect.pos.y + rect.height / 2;
  for (size_t i = 1; i < arr_size_; i++)
  {
    rect = array_[i]->getFrameRect();
    minX = std::min(minX, rect.pos.x - rect.width / 2);
    maxX = std::max(maxX, rect.pos.x + rect.width / 2);
    minY = std::min(minY, rect.pos.y - rect.height / 2);
    maxY = std::max(maxY, rect.pos.y + rect.height / 2);
  }
  return { maxX - minX, maxY - minY, { maxX - (maxX - minX) / 2, maxY - (maxY - minY) / 2 } };
}

void CompositeShape::move(const point_t &to_position) noexcept
{
  point_t tmp_centre = getFrameRect().pos;
  for (size_t i = 0; i < arr_size_; i++)
  {
    array_[i]->move(tmp_centre.x - to_position.x, tmp_centre.y - to_position.y);
  }
}

void CompositeShape::move(const double &dx, const double &dy) noexcept
{
  for (size_t i = 0; i < arr_size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void CompositeShape::scale(const double &coefficient)
{
  if (coefficient <= 0)
  {
    throw std::invalid_argument("Coefficient can't be <= 0!");
  }
  point_t tmp_centre = getFrameRect().pos;
  for (size_t i = 0; i < arr_size_; i++)
  {
    array_[i]->move({ tmp_centre.x + (array_[i]->getFrameRect().pos.x - tmp_centre.x) * coefficient,
     tmp_centre.y + (array_[0]->getFrameRect().pos.y - tmp_centre.y) * coefficient });
    array_[i]->scale(coefficient);
  }
}

void CompositeShape::rotate(double angle) noexcept
{
  point_t centre = CompositeShape::getFrameRect().pos;
  const double sin_a = std::sin((angle * M_PI) / 180);
  const double cos_a = std::cos((angle * M_PI) / 180);
  for (size_t i = 0; i < arr_size_; i++)
  {
    point_t centre_shape = array_[i]->getFrameRect().pos;
    array_[i]->move({ centre.x + (centre_shape.x - centre.x) * cos_a - (centre_shape.y - centre.y) * sin_a,
      centre.y + (centre_shape.y - centre.y) * cos_a + (centre_shape.x - centre.x) * sin_a });
    array_[i]->rotate(angle);
  }
}

void CompositeShape::addShape(Shape* shape)
{
  if (shape == nullptr)
  {
    throw std::invalid_argument("Object can't be nullptr!");
  }
  std::unique_ptr<Shape*[]> temp_array(new Shape*[arr_size_ + 1]);
  for (size_t i = 0; i < arr_size_; i++)
  {
    temp_array[i] = array_[i];
  }
  temp_array[arr_size_++] = shape;
  array_.swap(temp_array);
}

std::string CompositeShape::getName() const noexcept
{
  return "CompositeShape";
}

void CompositeShape::print(std::ostream & output) const noexcept
{
  output << "CompositeShape info: \n";
  for (size_t i = 0; i < arr_size_; i++)
  {
    array_[i]->print(output);
  }
}
