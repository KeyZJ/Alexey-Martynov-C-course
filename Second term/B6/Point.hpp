#ifndef POINT_HPP
#define POINT_HPP

#include <iosfwd>
#include <sstream>

struct  Point
{
  int x, y;
  Point(int x, int y) : x(x), y(y) {}
};

const char DELIMITER = ';';
const char OPEN_BRACKET = '(';
const char CLOSE_BRACKER = ')';

inline std::ostream & operator<<(std::ostream & out, const Point & point)
{
  return out << OPEN_BRACKET << point.x << DELIMITER << point.y << CLOSE_BRACKER;
}

inline std::istream & operator>>(std::istream & in, Point & point)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    char ch;
    in >> ch;
    if (ch != OPEN_BRACKET)
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    in >> point.x >> std::ws >> ch;
    if (ch != DELIMITER)
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    in >> point.y >> ch;
    if (ch != CLOSE_BRACKER)
    {
      in.setstate(std::istream::failbit);
      return in;
    }
  }
  return in;
}

#endif
