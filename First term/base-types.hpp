#ifndef BASETYPES_HPP
#define BASETYPES_HPP
#include <iostream>

struct point_t
{
  double x;
  double y;
};


point_t operator+(const point_t & lhs, const point_t & rhs);
point_t operator-(const point_t & lhs, const point_t & rhs);
bool operator>(const point_t & lhs, const point_t & rhs);
bool operator<(const point_t & lhs, const point_t & rhs);
bool operator==(const point_t & lhs, const point_t & rhs);
bool operator!=(const point_t & lhs, const point_t & rhs);
point_t & operator+(point_t & lhs, point_t & rhs);
point_t & operator-(point_t & lhs, point_t & rhs);
std::ostream & operator<<(std::ostream & output, const point_t & point);

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};

rectangle_t operator+(rectangle_t & lhs, rectangle_t & rhs);
rectangle_t operator-(rectangle_t & lhs, rectangle_t & rhs);
bool operator>(const rectangle_t & lhs, const rectangle_t & rhs);
bool operator<(const rectangle_t & lhs, const rectangle_t & rhs);
bool operator==(const rectangle_t &lhs, const rectangle_t &rhs);
bool operator!=(const rectangle_t &lhs, const rectangle_t &rhs);
std::ostream & operator<<(std::ostream & output, const rectangle_t & rect);

#endif
