#include "point1.hpp"
#include "point2.hpp"

#include <iostream>
#include <stdexcept>
#include <sstream>

int main(int argc, char * argv[])
{
  static const int SUCCESS  = 0;
  static const int ERROR = 1;

  if (argc != 2)
  {
    std::cerr << "There must me only one arguments, which is - lab point!\n";
    return ERROR;
  }
  int pointNumber = 0;
  std::istringstream in(argv[1]);
  in >> pointNumber;
  if (in.fail())
  {
    std::cerr << "First argument must be an integer digit, which is - lab point!\n";
    return ERROR;
  }
  try
  {
    switch (pointNumber)
    {
    case 1:
    {
      doFirstTask();
      break;
    }
    case 2:
    {
      doSecondTask();
      break;
    }
    default:
      std::cerr << "First argument must be an integer digit, which is - lab point!\n";
      return ERROR;
    }
  }
  catch (const std::runtime_error & e)
  {
    std::cerr << e.what() << "\n";
    return ERROR;
  }
  catch (...)
  {
    std::cerr << "Unknown exception!\n";
    return ERROR;
  }
  return SUCCESS;
}
