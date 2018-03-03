#include "point2.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "square.hpp"

#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include <list>
#include <stdexcept>
#include <iterator>
#include <locale>

std::istream & operator>>(std::istream & in, std::shared_ptr<Shape> & shape)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string shapeType; 
    in >> std::ws >> shapeType;
    Point centre(0, 0);
    in >> centre;
    if (in.eof())
    {
      in.clear(std::istream::failbit);
      return in;
    }
    if (in.fail() && !in.eof())
    {
      in.setstate(std::istream::failbit);
      return in;
    }
    if (shapeType == "CIRCLE")
    {
      shape = std::shared_ptr<Shape>(new Circle(centre));
    }
    else if (shapeType == "TRIANGLE")
    {
      shape = std::shared_ptr<Shape>(new Triangle(centre));
    }
    else if (shapeType == "SQUARE")
    {
      shape = std::shared_ptr<Shape>(new Square(centre));
    }
    else
    {
      in.clear(std::istream::failbit);
      return in;
    }
  }
  return in;
}


void doPoint2()
{
  std::list<std::shared_ptr<Shape>> shapeList{ std::istream_iterator<std::shared_ptr<Shape>>(std::cin),
    std::istream_iterator<std::shared_ptr<Shape>>() };
  if (std::cin.fail())
  {
    if (!std::cin.eof())
    {
      throw std::runtime_error("Invalid input.");
    }
  }

  std::cout << "Original:" << std::endl;
  std::for_each(shapeList.begin(), shapeList.end(),
    std::bind(&Shape::draw, std::placeholders::_1, std::ref(std::cout)));

  shapeList.sort(std::bind(&Shape::isMoreLeft, std::placeholders::_1, std::placeholders::_2));
  std::cout << "Left-Right:" << std::endl;
  std::for_each(shapeList.begin(), shapeList.end(),
    std::bind(&Shape::draw, std::placeholders::_1, std::ref(std::cout)));

  shapeList.sort(std::bind(&Shape::isMoreLeft, std::placeholders::_2, std::placeholders::_1));
  std::cout << "Right-Left:" << std::endl;
  std::for_each(shapeList.begin(), shapeList.end(),
    std::bind(&Shape::draw, std::placeholders::_1, std::ref(std::cout)));

  shapeList.sort(std::bind(&Shape::isUpper, std::placeholders::_1, std::placeholders::_2));
  std::cout << "Top-Bottom:" << std::endl;
  std::for_each(shapeList.begin(), shapeList.end(),
    std::bind(&Shape::draw, std::placeholders::_1, std::ref(std::cout)));

  shapeList.sort(std::bind(&Shape::isUpper, std::placeholders::_2, std::placeholders::_1));
  std::cout << "Bottom-Top:" << std::endl;
  std::for_each(shapeList.begin(), shapeList.end(),
    std::bind(&Shape::draw, std::placeholders::_1, std::ref(std::cout)));
}
