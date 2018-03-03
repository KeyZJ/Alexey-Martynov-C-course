#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "compositeshape.hpp"
#include "matrix.hpp"

int main()
{
  try
  {
    Rectangle oRectangle{ { 1, 1 }, 2, 3 };
    Circle oCircle{ { 1, 1 }, 6 };
    Triangle oTriangle{ { 0, 0 },{ 10, 10 },{ 20, 0 } };
    Rectangle ooRectangle{ { 2, 2 }, 4, 6 };
    Circle ooCircle{ { 2, 2 }, 12 };
    Triangle ooTriangle{ { 0, 0 },{ 20, 20 },{ 40, 0 } };
    CompositeShape oCompositeShape(&oRectangle);
    oCompositeShape.addShape(&oCircle);
    oCompositeShape.addShape(&oTriangle);
    Matrix oMatrix(&oCompositeShape);
    oMatrix.addShape(&ooRectangle);
    oMatrix.addShape(&ooCircle);
    oMatrix.addShape(&ooTriangle);
    std::cout << oMatrix;
  }
  catch (...)
  {
    std::cout << "\n";
  }
  return 0;
}
