#include "uttils.hpp"

#include <iterator>

namespace uttills
{
  bool isAscending(const char * direction)
  {
    std::string tmp = direction;
    if (tmp == "ascending")
    {
      return true;
    }
    else if (tmp == "descending")
    {
      return false;
    }
    else
    {
      throw std::runtime_error("Invalid argument: should be \"ascending\" or \"descending\".");
    }
  }

  void readToVector(std::vector<int> & data)
  {
    std::istream_iterator<int> in{ std::cin }, eof;
    std::back_insert_iterator<std::vector<int>> target(data);
    while (in != eof)
    {
      *target = *in;
      ++in;
      ++target;
    }
    if (!std::cin.eof())
    {
      throw std::runtime_error("Invalid input: must be an integer!\n");
    }
  }

  void readToVector(std::vector<int> & data, const int & end)
  {
    std::istream_iterator<int> in{ std::cin }, eof;
    std::back_insert_iterator<std::vector<int>> target(data);
    while (in != eof)
    {
      *target = *in;
      ++in;
      ++target;
    }
    if (!std::cin.eof())
    {
      throw std::runtime_error("Invalid input: must be an integer!\n");
    }
    if (data.empty())
    {
      return;
    }
    if (data.back() == end)
    {
      data.pop_back();
    }
    else
    {
      throw std::runtime_error("Invalid input: there must be an 0 at the end of the vector!\n");
    }
  }
}
