#include "processingQueue.hpp"
#include "QueueWithPriority.hpp"
#include "ReadPrintList.hpp"

#include <iostream>
#include <sstream>

int main(int argc, char * argv[])
{
  const int arguments = 2;
  if (argc != arguments)
  {
    std::cerr << "There must be only one argument: task number!\n";
    return 1;
  }

  int pointNumber = 0;
  std::istringstream iss(argv[1]);
  iss >> pointNumber;
  if (iss.fail())
  {
    std::cerr << "First argument must be a point number!\n";
    return 1;
  }

  try
  {
    switch (pointNumber)
    {
    case 1:
      {
        readCommand();
        break;
      }
    case 2:
      {
        std::list<int> data;
        read(data);
        print(data);
        break;
      }
    default:
      {
        std::cerr << "The point number must be 1 or 2!\n";
        return 1;
      }
    }
  }
  catch (std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Unknown error!\n";
    return 2;
  }
  return 0;
}
