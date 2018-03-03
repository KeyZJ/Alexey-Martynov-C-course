#include "FactorialContainer.hpp"

#include <iostream>

FactorialContainer::iterator & FactorialContainer::iterator::operator++()
{
  ++current_;
  ++num_;
  return *this;
}

FactorialContainer::iterator FactorialContainer::iterator::operator++(int)
{
  FactorialContainer::iterator tmp(*this);
  num_++;
  current_++;
  return tmp;
}

FactorialContainer::iterator & FactorialContainer::iterator::operator--()
{
  --current_;
  --num_;
  return *this;
}

FactorialContainer::iterator FactorialContainer::iterator::operator--(int)
{
  FactorialContainer::iterator tmp(*this);
  current_--;
  num_--;
  return tmp;
}

bool FactorialContainer::iterator::operator==(const FactorialContainer::iterator & rhs)
{
  return num_ != rhs.num_;
}

bool FactorialContainer::iterator::operator!=(const FactorialContainer::iterator & rhs)
{
  return num_ != rhs.num_;
}

int FactorialContainer::iterator::operator*()
{
  int tmp = 0;
  switch (num_)
  {
  case 1:
  {
    tmp = Factorial<1>::factorial;
    break;
  }
  case 2:
  {
    tmp = Factorial<2>::factorial;
    break;
  }
  case 3:
  {
    tmp = Factorial<3>::factorial;
    break;
  }
  case 4:
  {
    tmp = Factorial<4>::factorial;
    break;
  }
  case 5:
  {
    tmp = Factorial<5>::factorial;
    break;
  }
  case 6:
  {
    tmp = Factorial<6>::factorial;
    break;
  }
  case 7:
  {
    tmp = Factorial<7>::factorial;
    break;
  }
  case 8:
  {
    tmp = Factorial<8>::factorial;
    break;
  }
  case 9:
  {
    tmp = Factorial<9>::factorial;
    break;
  }
  case 10:
  {
    tmp = Factorial<10>::factorial;
    break;
  }
  }
  return tmp;
}

FactorialContainer::reverse_iterator & FactorialContainer::reverse_iterator::operator++()
{
  --current_;
  --num_;
  return *this;
}

FactorialContainer::reverse_iterator FactorialContainer::reverse_iterator::operator++(int)
{
  FactorialContainer::reverse_iterator tmp(*this);
  num_--;
  current_--;
  return tmp;
}

FactorialContainer::reverse_iterator & FactorialContainer::reverse_iterator::operator--()
{
  ++current_;
  ++num_;
  return *this;
}

FactorialContainer::reverse_iterator FactorialContainer::reverse_iterator::operator--(int)
{
  FactorialContainer::reverse_iterator tmp(*this);
  num_++;
  current_++;
  return tmp;
}
