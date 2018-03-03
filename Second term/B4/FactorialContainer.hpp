#ifndef FACTORIAL_CONTAINER_HPP
#define FACTORIAL_CONTAINER_HPP

#include <iterator>

class FactorialContainer
{
public:
  class iterator : public std::iterator<std::bidirectional_iterator_tag, int>
  {
  public:
    iterator(int num) : num_(num) {};
    iterator & operator++();
    iterator operator++(int);
    iterator & operator--();
    iterator operator--(int);
    bool operator==(const iterator & rhs);
    bool operator!=(const iterator & rhs);
    int operator*();
  protected:
    int * current_;
    int num_;
  };

  class reverse_iterator : public iterator
  {
  public:
    reverse_iterator(int num) : iterator(num) {};
    reverse_iterator& operator++();
    reverse_iterator operator++(int);
    reverse_iterator& operator--();
    reverse_iterator operator--(int);
  };

  iterator begin()
  {
    return iterator(1);
  }
  iterator end()
  {
    return iterator(11);
  }

  reverse_iterator rbegin()
  {
    return reverse_iterator(10);
  }
  reverse_iterator rend()
  {
    return reverse_iterator(0);
  }
};

template<int n>
class Factorial
{
public:
  static const int factorial = Factorial<n - 1>::factorial*n;
};
template<>
class Factorial<0>
{
public:
  static const int factorial = 1;
};

#endif
