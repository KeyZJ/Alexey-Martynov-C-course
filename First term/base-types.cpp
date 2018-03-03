#include "base-types.hpp"
#include <iostream>

point_t operator-(const point_t & lhs, const point_t & rhs)
{
  lhs.x - rhs.x;
  lhs.y - rhs.y;
  return lhs;
}

point_t operator+(const point_t & lhs, const point_t & rhs)
{
  lhs.x + rhs.x;
  lhs.y + rhs.y;
  return lhs;
}

bool operator>(const point_t & lhs, const point_t & rhs)
{
  if ((lhs.x > rhs.x) && (lhs.y > rhs.y))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool operator<(const point_t & lhs, const point_t & rhs)
{
  if ((lhs.x < rhs.x) && (lhs.y < rhs.y))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool operator==(const point_t & lhs, const point_t & rhs)
{
  return ((lhs.x == rhs.x) && (lhs.y == rhs.y));
}

bool operator!=(const point_t & lhs, const point_t & rhs)
{
  return !(lhs == rhs);
}

point_t & operator+(point_t & lhs, point_t & rhs)
{
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  return lhs;
}

point_t & operator-(point_t & lhs, point_t & rhs)
{
  lhs.x -= rhs.x;
  lhs.y -= rhs.y;
  return lhs;
}

std::ostream & operator<<(std::ostream & output, const point_t & point)
{
  output << "{" << point.x << ", " << point.y << "}";
  return output;
}

rectangle_t operator+(rectangle_t & lhs, rectangle_t & rhs)
{
  lhs.width += rhs.width;
  lhs.height += rhs.height;
  lhs.pos = lhs.pos + rhs.pos;
  return lhs;
}

rectangle_t operator-(rectangle_t & lhs, rectangle_t & rhs)
{
  lhs.width -= rhs.width;
  lhs.height -= rhs.height;
  lhs.pos = lhs.pos - rhs.pos;
  return lhs;
}

bool operator>(const rectangle_t & lhs, const rectangle_t & rhs)
{
  if ((lhs.width > rhs.width) && (lhs.height > rhs.height) && (lhs.pos > rhs.pos))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool operator<(const rectangle_t & lhs, const rectangle_t & rhs)
{
  if ((lhs.width < rhs.width) && (lhs.height < rhs.height) && (lhs.pos < rhs.pos))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool operator==(const rectangle_t & lhs, const rectangle_t & rhs)
{
  return ((lhs.pos == rhs.pos) && (lhs.height == rhs.height) && (lhs.width == rhs.width));
}

bool operator!=(const rectangle_t & lhs, const rectangle_t & rhs)
{
  return !(lhs == rhs);
}

std::ostream & operator<<(std::ostream & output, const rectangle_t & rect)
{
  output << "(" << rect.width << ", " << rect.height << ", " << rect.pos << ")";
  return output;
}
