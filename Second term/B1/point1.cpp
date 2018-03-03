#include "point1.hpp"
#include "uttils.hpp"

#include <iostream>
#include <vector>
#include <iterator>
#include <forward_list>

void sortContainer(int argc, char * argv[])
{
  const int arguments = 3;
  if (argc != arguments)
  {
    throw std::invalid_argument("Invalid arguments! You must enter: point_number ascending/descending!\n");
  }

  bool whichOrder = uttills::isAscending(argv[2]);

  std::vector<int> data;
  uttills::readToVector(data);

  std::vector<int> vectorSortedWithOperator{ data };
  std::vector<int> vectorSortedWithAt{ data };
  std::forward_list<int> list(data.begin(), data.end());

  sort(vectorSortedWithOperator, uttills::GetWithOperator<std::vector<int>>(), whichOrder);
  sort(vectorSortedWithAt, uttills::GetWithAt<std::vector<int>>(), whichOrder);
  sort(list, uttills::GetWithIterator<std::forward_list<int>>(), whichOrder);

  uttills::printContainer(vectorSortedWithOperator, true);
  uttills::printContainer(vectorSortedWithAt, true);
  uttills::printContainer(list, true);
}
