#include "point1.hpp"

#include <iostream>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>

void doFirstTask()
{
  std::set<std::string> data;
  std::copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::inserter(data, data.begin()));
  std::ostream_iterator<std::string> output(std::cout, "\n");
  std::copy(data.begin(), data.end(), output);
}
