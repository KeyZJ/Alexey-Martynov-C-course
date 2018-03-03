#ifndef BOOST_TEST_MAIN
#define BOOST_TEST_MAIN
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "compositeshape.hpp"
#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

BOOST_AUTO_TEST_CASE(not_correct_construcor)
{
  Shape *oShape = nullptr;
  BOOST_CHECK_THROW(CompositeShape oCompositeShape(oShape), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(compositeshape_rectangle)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  CompositeShape oCompositeShape(&oRectangle);
  BOOST_CHECK(&oCompositeShape[0] == &oRectangle);
}
BOOST_AUTO_TEST_CASE(compositeshape_circle)
{
  Circle oCircle{ { 1, 1 }, 6 };
  CompositeShape oCompositeShape(&oCircle);
  BOOST_CHECK(&oCompositeShape[0] == &oCircle);
}
BOOST_AUTO_TEST_CASE(compositeshape_triangle)
{
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oTriangle);
  BOOST_CHECK(&oCompositeShape[0] == &oTriangle);
}
BOOST_AUTO_TEST_CASE(not_correct_addShape)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  CompositeShape oCompositeShape(&oRectangle);
  Shape *oShape = nullptr;
  BOOST_CHECK_THROW(oCompositeShape.addShape(oShape), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(add_compositeshape_rectangle)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  CompositeShape oCompositeShape(&oRectangle);
  Rectangle ooRectangle{ { 5, 5 }, 5, 5 };
  oCompositeShape.addShape(&ooRectangle);
  BOOST_CHECK(&oCompositeShape[1] == &ooRectangle);
}
BOOST_AUTO_TEST_CASE(area_compositeshape)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  BOOST_CHECK_CLOSE(oRectangle.getArea() + oCircle.getArea() + oTriangle.getArea(), oCompositeShape.getArea(), 0.01);
}
BOOST_AUTO_TEST_CASE(move_to_position_area_compositeshape)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  const double past_area = oCompositeShape.getArea();
  oCompositeShape.move({ 5,5 });
  BOOST_CHECK_CLOSE(past_area, oCompositeShape.getArea(), 0.01);
}
BOOST_AUTO_TEST_CASE(move_by_axis_area_compositeshape)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  const double past_area = oCompositeShape.getArea();
  oCompositeShape.move(2, 3);
  BOOST_CHECK_CLOSE(past_area, oCompositeShape.getArea(), 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_increase)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  const double past_area = oCompositeShape.getArea();
  oCompositeShape.scale(2);
  BOOST_CHECK_CLOSE(past_area, oCompositeShape.getArea() / 4, 0.01);
}
BOOST_AUTO_TEST_CASE(area_scaling_decrease)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  const double past_area = oCompositeShape.getArea();
  oCompositeShape.scale(0.5);
  BOOST_CHECK_CLOSE(past_area, oCompositeShape.getArea() * 4, 0.01);
}
BOOST_AUTO_TEST_CASE(scale_wrong_negative_coefficient)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  BOOST_CHECK_THROW(oCompositeShape.scale(-99), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(scale_wrong_null_coefficient)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  Circle oCircle{ { 1, 1 }, 6 };
  Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
  CompositeShape oCompositeShape(&oRectangle);
  oCompositeShape.addShape(&oCircle);
  oCompositeShape.addShape(&oTriangle);
  BOOST_CHECK_THROW(oCompositeShape.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(two_compositeshapes)
{
  Rectangle oRectangle{ { 1, 1 }, 2, 3 };
  CompositeShape cs_lhs(&oRectangle);
  CompositeShape cs_rhs(&oRectangle);
  BOOST_CHECK(&cs_lhs[0] == &cs_rhs[0]);
}

#endif
