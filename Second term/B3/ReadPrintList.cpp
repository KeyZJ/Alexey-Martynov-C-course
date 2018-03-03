#include "ReadPrintList.hpp"

#include <list>
#include <iostream>
#include <iterator>

void read(std::list<int> & list)
{
  std::istream_iterator<int> in{ std::cin }, eof;
  std::back_insert_iterator<std::list<int>> target(list);
  const int minValue = 1;
  const int maxValue = 20;
  while (in != eof)
  {
    if ((*in >= minValue) && (*in <= maxValue) && (list.size() < maxValue))
    {
      *target = *in;
      ++in;
      ++target;
    }
    else
    {
      std::cin.setstate(std::istream::failbit);
      break;
    }
  }
  if (!std::cin.eof())
  {
    throw std::runtime_error("Invalid input: you must enter integer up to 20 numbers from 1 to 20!");
  }
}

void print(std::list<int> & list)
{
  if (!list.empty())
  {
    std::list<int>::iterator it = list.begin();
    std::list<int>::reverse_iterator revIt = list.rbegin();
    size_t middle = list.size() / 2;
    if (list.size() == 1)
    {
      std::cout << *it;
    }
    else 
    {
      while (true)
      {
        std::cout << *it << ' ';
        std::cout << *revIt;
        --middle;
        if (middle == 0)
        {
          break;
        }
        std::cout << ' ';
        ++it;
        ++revIt;
      }
      if (list.size() % 2 != 0)
      {
        std::cout << ' ' << (*++it);
      }
    }
  }
  else
  {
    return;
  }
}
