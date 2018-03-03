#include "point3.hpp"
#include "uttils.hpp"

void modifyVector(int argc)
{
  const int arguments = 2;
  if (argc != arguments)
  {
    throw std::invalid_argument("Invalid arguments! You must enter point_number!\n");
  }
  std::vector<int> data;
  uttills::readToVector(data,0);
  if (data.empty())
  {
    return;
  }
  std::vector<int>::iterator it = data.begin();
  if (data.back() == 1)
  {
    while (it != data.end())
    {
      if ((*it % 2) == 0)
      {
        it = data.erase(it);
      }
      else
      {
        ++it;
      }
    }
  }
  else if (data.back() == 2)
  {
    while (it != data.end())
    {
      if ((*it % 3) == 0)
      {
        it = data.insert(++it, 3, 1);
      }
      else
      {
        ++it;
      }
    }
  }
  else
  {
    uttills::printContainer(data, true);
    return;
  }
  uttills::printContainer(data, true);
}
