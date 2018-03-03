#include "point1.hpp"

#define _USE_MATH_DEFINES 

#include <algorithm>
#include <iterator>
#include <cmath>
#include <iostream>
#include <functional>

void doPoint1()
{
  std::cout.precision(8);
  std::cout << std::fixed;
  std::transform(std::istream_iterator<double>(std::cin), std::istream_iterator<double>(),
    std::ostream_iterator<double>(std::cout, " "), std::bind1st(std::multiplies<double>(), M_PI));
  if (std::cin.fail())
  {
    if (std::cin.eof())
    {
      return;
    }
    throw std::runtime_error("Invalid input: you must enter only double type of digits!");
  }
  std::cout << "\n";
}
