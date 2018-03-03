#include "Interface.hpp"
#include "FactorialContainer.hpp"

#include <iostream>
#include <sstream>
#include <iterator>

int main(int argc, char * argv[])
{
  const int successCode = 0;
  const int errorCode = 2;

  const int arguments = 1;

  if (argc != (arguments + 1))
  {
    throw std::invalid_argument("There should be 1 argument - number of task.");
  }

  int labNumber = 0;
  std::istringstream stream(argv[1]);
  stream >> labNumber;
  if (stream.fail())
  {
    throw std::invalid_argument("The first argument must be a number.");
  }

  try
  {
    switch (labNumber)
    {
    case 1:
      {
        Interface userInterface;
        userInterface.readCommand();
        break;
      }
    case 2:
      {
        FactorialContainer factorialContainer;
        std::copy(factorialContainer.begin(), factorialContainer.end(),
        std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";

        std::copy(factorialContainer.rbegin(), factorialContainer.rend(),
        std::ostream_iterator<int>(std::cout, " "));
        std::cout << "\n";
        break;
      }
    default:
      {
      throw std::invalid_argument("The first argument must be a task number. (1 or 2).");
      }
    }
  }
  catch (std::exception & e)
  {
    std::cerr << e.what << "\n";
    return errorCode;
  }
  catch (...)
  {
    std::cerr << "Unknown exception!\n";
    return errorCode;
  }

  return successCode;
}
