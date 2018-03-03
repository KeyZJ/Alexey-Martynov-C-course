#include "point1.hpp"
#include "point2.hpp"

#include <stdexcept>
#include <iostream>
#include <sstream>

int main(int argc, char * argv[])
{
  const int SUCCESS = 0;
  const int ERROR = 1;

  if (argc != 2)
  {
    std::cerr << "There must me only one arguments, which is - lab point!\n";
    return ERROR;
  }

  int labNumber = 0;
  std::istringstream in(argv[1]);
  in >> labNumber;

  if (in.fail())
  {
    std::cerr << "There must me only one arguments, which is - lab point!\n";
  }

  try
  {
    switch (labNumber)
    {
    case 1:
      {
        doPoint1();
        break;
      }
    case 2:
      {
        doPoint2();
        break;
      }
    default:
      {
        std::cerr << "First argument must be an integer digit, which is - lab point!\n";
        return ERROR;
      }
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
