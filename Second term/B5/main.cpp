#include "DataStruct.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
  try
  {
    std::vector<DataStruct> data((std::istream_iterator<DataStruct>(std::cin)), std::istream_iterator<DataStruct>());
    if (!std::cin)
    {
      if (!std::cin.eof())
      {
        throw std::runtime_error("Invalid input!");
      }
    }
    std::sort(data.begin(), data.end());
    std::copy(data.begin(), data.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));
  }
  catch (std::runtime_error & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Exception!\n";
    return 2;
  }
}
