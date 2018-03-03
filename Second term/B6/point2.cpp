#include "point2.hpp"

#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>

std::ostream & operator<<(std::ostream & out, const Shape & shape)
{
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  return out;
}

bool isTriangle(const Shape & shape)
{
  return (shape.size() == 3);
}

bool isRectangle(const Shape & shape)
{
  if (shape.size() == 4)
  {
    return (shape[0].x == shape[1].x) && (shape[2].x == shape[3].x)
      && (shape[0].y == shape[3].y) && (shape[1].y == shape[2].y);
  }
  else
  {
    return false;
  }
}

bool isSquare(const Shape & shape)
{
  if (isRectangle(shape))
  {
    return (std::abs(shape[0].x - shape[3].x) == std::abs(shape[1].x - shape[2].x)
      && (std::abs(shape[0].y - shape[1].y) == std::abs(shape[3].y - shape[2].y))
      && (std::abs(shape[0].x - shape[3].x) == std::abs(shape[0].y - shape[1].y)));
  }
  else
  {
    return false;
  }
}

void read(std::vector<Shape> & shapes)
{
  while (true)
  {
    std::string input;
    std::getline (std::cin >> std::ws, input);
    if (!std::cin.fail())
    {
      std::istringstream inStream(input);
      std::vector<Shape>::size_type pointsNumber = 0;
      inStream >> pointsNumber;
      Shape inShape;
      Point inPoint(0, 0);
      for (std::vector<Shape>::size_type i = 0; i < pointsNumber; ++i)
      {
        inStream >> inPoint;
        if (inStream.fail())
        {
          throw std::runtime_error("Invalid input of a new shape!");
        }
        inShape.push_back(inPoint);
      }
      inStream >> inPoint;
      if (!inStream.fail())
      {
        throw std::runtime_error("Invalid input: there more point than needed!");
      }
      shapes.push_back(inShape);
    }
    else
    {
      if (std::cin.eof())
      {
        break;
      }
      else
      {
        throw std::runtime_error("Invalid input of a new shape!");
      }
    }
  }
}

void doSecondTask()
{
  std::vector<Shape> shapes;
  read(shapes);
  std::vector<Shape>::size_type verticlesNumber = std::accumulate(shapes.begin(), shapes.end(), std::vector<Shape>::size_type(0),
    [](std::vector<Shape>::size_type currentSum, Shape & currentElement)
  {
    return currentSum + currentElement.size();
  });

  std::vector<Shape>::size_type triangleNumber = count_if(shapes.begin(), shapes.end(), isTriangle);
  std::vector<Shape>::size_type squareNumber = count_if(shapes.begin(), shapes.end(), isSquare);
  std::vector<Shape>::size_type rectangleNumber = count_if(shapes.begin(), shapes.end(), isRectangle);

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), [](Shape & currentElement)
  {
    return (currentElement.size() == 5);
  }), shapes.end());

  std::vector<Point> points;
  for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
  {
    points.push_back(it->front());
  }

  std::stable_sort(shapes.begin(), shapes.end(), [](const Shape & a, const Shape & b)
  {
    return ( ((a.size() < b.size()) && (b.size() < 5 || a.size() < 5)) || (isSquare(a) && isRectangle(b) && !isSquare(b)));
  });

  std::cout << "Vertices: " << verticlesNumber << "\n";
  std::cout << "Triangles: " << triangleNumber << "\n";
  std::cout << "Squares: " << squareNumber << "\n";
  std::cout << "Rectangles: " << rectangleNumber << "\n";
  std::cout << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(std::cout, " "));
  std::cout << "\n";
  std::cout << "Shapes: " << "\n";
  for (std::vector<Shape>::iterator it = shapes.begin(); it != shapes.end(); ++it)
  {
    std::cout << it->size() << " " << *it << "\n";
  }
}
