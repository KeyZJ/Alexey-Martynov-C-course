#ifndef BOOST_TEST_MAIN
#define BOOST_TEST_MAIN
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

BOOST_AUTO_TEST_SUITE(Rectangle_tests)
BOOST_AUTO_TEST_CASE(area_permanenty_after_move_on)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  const double area = oRectangle.getArea();
  oRectangle.move(2, 3);
  BOOST_CHECK_CLOSE(oRectangle.getArea(), area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_permanenty_after_move_to)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  const double area = oRectangle.getArea();
  oRectangle.move({ 5, 5 });
  BOOST_CHECK_CLOSE(oRectangle.getArea(), area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_increase)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  double area = oRectangle.getArea();
  oRectangle.scale(2);
  BOOST_CHECK_CLOSE(oRectangle.getArea(), 4 * area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_decrease)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  double area = oRectangle.getArea();
  oRectangle.scale(0.5);
  BOOST_CHECK_CLOSE(oRectangle.getArea(), area / 4, 0.01);
}
BOOST_AUTO_TEST_CASE(scale_test)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  BOOST_CHECK_THROW(oRectangle.scale(-99), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Circle_tests)
BOOST_AUTO_TEST_CASE(radius_permanenty_after_move_on)
{
  Circle oCircle{ { 1, 1 }, 6 };
  const double radius = oCircle.getRadius();
  oCircle.move(2, 3);
  BOOST_CHECK_CLOSE(oCircle.getRadius(), radius, 0.01);
}
BOOST_AUTO_TEST_CASE(radius_permanenty_after_move_to)
{
  Circle oCircle{ { 1, 1 }, 6 };
  const double radius = oCircle.getRadius();
  oCircle.move({ 5, 5 });
  BOOST_CHECK_CLOSE(oCircle.getRadius(), radius, 0.01);
}
BOOST_AUTO_TEST_CASE(area_permanenty_after_move_on)
{
  Circle oCircle{ { 1, 1 }, 6 };
  const double area = oCircle.getArea();
  oCircle.move(2, 3);
  BOOST_CHECK_CLOSE(oCircle.getArea(), area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_permanenty_after_move_to)
{
  Circle oCircle{ { 1, 1 }, 6 };
  const double area = oCircle.getArea();
  oCircle.move({ 5, 5 });
  BOOST_CHECK_CLOSE(oCircle.getArea(), area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_increase)
{
  Circle oCircle{ { 1, 1 }, 6 };
  double area = oCircle.getArea();
  oCircle.scale(2);
  BOOST_CHECK_CLOSE(oCircle.getArea(), 4 * area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_decrease)
{
  Circle oCircle{ { 1, 1 }, 6 };
  double area = oCircle.getArea();
  oCircle.scale(0.5);
  BOOST_CHECK_CLOSE(oCircle.getArea(), area / 4, 0.01);
}
BOOST_AUTO_TEST_CASE(radius_test)
{
  Circle oCircle{ { 1, 1 }, 6 };
  BOOST_CHECK_THROW(oCircle.setRadius(-99), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(scale_test)
{
  Circle oCircle{ { 1, 1 }, 6 };
  BOOST_CHECK_THROW(oCircle.scale(-99), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Triangle_tests)
BOOST_AUTO_TEST_CASE(area_permanenty_after_move_on)
{
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  const double area = oTriangle.getArea();
  oTriangle.move(2, 3);
  BOOST_CHECK_CLOSE(oTriangle.getArea(), area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_permanenty_after_move_to)
{
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  const double area = oTriangle.getArea();
  oTriangle.move({ 5, 5 });
  BOOST_CHECK_CLOSE(oTriangle.getArea(), area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_increase)
{
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  double area = oTriangle.getArea();
  oTriangle.scale(2);
  BOOST_CHECK_CLOSE(oTriangle.getArea(), 4 * area, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_decrease)
{
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  double area = oTriangle.getArea();
  oTriangle.scale(0.5);
  BOOST_CHECK_CLOSE(oTriangle.getArea(), area / 4, 0.01);
}
BOOST_AUTO_TEST_CASE(points_test)
{
  BOOST_CHECK_THROW(Triangle tri({ 10, 10 }, { 10, 10 }, { 10, 10 }), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(scale_test)
{
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  BOOST_CHECK_THROW(oTriangle.scale(-99), std::invalid_argument);
}
BOOST_AUTO_TEST_SUITE_END()
#endif
