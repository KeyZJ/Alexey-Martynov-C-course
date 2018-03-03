#include "point1.hpp"
#include "point2.hpp"
#include "point3.hpp"
#include "point4.hpp"

#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char * argv[])
{
  constexpr int minArguments = 1;
  constexpr int successCode = 0;
  constexpr int errorCode = 1;
  constexpr int invalidArguments = 1;
  if (argc < minArguments + 1)
  {
    std::cerr << "Must be at least 1 argument!\n";
    return invalidArguments;
  }
  int pointID = 0;
  std::istringstream input(argv[1]);
  input >> pointID;
  if (input.fail())
  {
    std::cerr << "First argument must be a task number [1,4]!\n";
    return invalidArguments;
  }
  try
  {
    switch (pointID)
    {
    case 1:
    {
      sortContainer(argc, argv);
      break;
    }
    case 2:
    {
      readFile(argc, argv);
      break;
    }
    case 3:
    {
      modifyVector(argc);
      break;
    }
    case 4:
    {
      fillAndSortVector(argc, argv);
      break;
    }
    default:
    {
      std::cerr << "First argument must be a task number [1,4]!\n";
      return invalidArguments;
    }
    }
    return successCode;
  }
  catch (std::invalid_argument & e)
  {
    std::cerr << e.what();
    return errorCode;
  }
  catch (std::runtime_error & e)
  {
    std::cerr << e.what();
    return errorCode;
  }
  catch (...)
  {
    std::cerr << "Unknown error!\n";
    return errorCode;
  }
}
