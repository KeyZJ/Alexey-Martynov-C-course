#ifndef UTTILS_HPP
#define UTTILS_HPP

#include <vector>
#include <iostream>

namespace uttills
{
  template< typename T >
  class GetWithOperator
  {
  public:
    typename T::reference operator()(T & container, size_t i)
    {
      return container[i];
    }
    size_t begin(const T &) const
    {
      return 0;
    }
    size_t end(const T & container) const
    {
      return container.size();
    }
  };

  template< typename T >
  class GetWithAt
  {
  public:
    typename T::reference operator()(T & container, size_t i)
    {
      return container.at(i);
    }
    size_t begin(const T &) const
    {
      return 0;
    }
    size_t end(const T & container) const
    {
      return container.size();
    }
  };

  template< typename T >
  class GetWithIterator
  {
  public:
    typename T::reference operator()(T &, typename T::iterator it)
    {
      return *it;
    }
    typename T::iterator begin(T & container)
    {
      return container.begin();
    }
    typename T::iterator end(T & container)
    {
      return container.end();
    }
  };

  template<typename Container, typename Access>
  void sort(Container & container, Access access, bool isAscending)
  {
    for (auto i = access.begin(container); i != access.end(container); ++i)
    {
      for (auto j = i; j != access.end(container); ++j)
      {
        if ((access(container, i) > access(container, j) && isAscending) || (access(container, i) < access(container, j) && !isAscending))
        {
          std::swap(access(container, j), access(container, i));
        }
      }
    }
  }

  template< typename T >
  void printContainer(const T & container, bool delimiter)
  {
    if (delimiter)
    {
      for (typename T::const_iterator it = container.cbegin(); it != container.cend(); ++it)
      {
        std::cout << *it << ' ';
      }
      std::cout << "\n";
    }
    else
    {
      for (typename T::const_iterator it = container.cbegin(); it != container.cend(); ++it)
      {
        std::cout << *it;
      }
    }
  }

  bool isAscending(const char * direction);
  void readToVector(std::vector<int> & data);
  void readToVector(std::vector<int> & data, const int & end);
}
#endif
