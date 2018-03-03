#include "point4.hpp"
#include "uttils.hpp"
#include "point1.hpp"

#include <stdexcept>
#include <random>
#include <iostream>
#include <sstream>

void fillRandom(double * array, int size)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("The array point is nullptr!\n");
  }
  else if (size < 0)
  {
    throw std::invalid_argument("The array size is < 0!\n");
  }
  std::random_device randomDevice;
  std::default_random_engine randomEngine(randomDevice());
  std::uniform_real_distribution<double> distribution(-1.0, 1.0);
  for (int i = 0; i < size; ++i)
  {
    array[i] = distribution(randomEngine);
  }
}

void fillAndSortVector(int argc, char * argv[])
{
  const int arguments = 3;
  if (argc != arguments + 1)
  {
    throw std::invalid_argument("Invalid arguments! You must enter: point_number ascending/descending vector_size!\n");
  }
  bool isAscending = uttills::isAscending(argv[2]);

  size_t size = 0;
  std::string str(argv[3]);
  std::istringstream(str) >> size;

  if (size < 1)
  {
    throw std::invalid_argument("Size of the vector can't be less than 1!\n");
  }

  std::vector<double> data(size);
  fillRandom(data.data(), size);
  uttills::printContainer(data, true);
  
  uttills::sort(data, uttills::GetWithOperator<std::vector<double>>(), isAscending);
  uttills::printContainer(data, true);

}
