#include <limits>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <iomanip>

class MyFunctor
{
public:
  MyFunctor() :
    max(std::numeric_limits<long int>::min()),
    min(std::numeric_limits<long int>::max()),
    positiveCount(0),
    negativeCount(0),
    evenSum(0),
    oddSum(0),
    elementCount(0),
    elementSum(0),
    firstElement(0),
    lastElement(0)
  {}
  
  bool empty() const
  {
    return (elementCount == 0);
  }

  void operator()(const long int & element)
  {
    if (empty())
    {
      firstElement = element;
    }
    lastElement = element;

    if (element > max)
    {
      max = element;
    }

    if (element < min)
    {
      min = element;
    }

    if (element > 0)
    {
      ++positiveCount;
    }

    if (element < 0)
    {
      ++negativeCount;
    }

    if (element % 2 == 0)
    {
      evenSum += element;
    }
    else
    {
      oddSum += element;
    }

    ++elementCount;
    elementSum += element;
  }

  long int getMax() const
  {
    return max;
  }

  long int getMin() const
  {
    return min;
  }

  long double getMean() const
  {
    return empty() ? 0 : static_cast<long double>(elementSum) / static_cast<long double>(elementCount);
  }

  long int getPositives() const
  {
    return positiveCount;
  }

  long int getNegatives() const
  {
    return negativeCount;
  }

  long int getOddSum() const
  {
    return oddSum;
  }

  long int getEvenSum() const
  {
    return evenSum;
  }

  bool isFirstEqualLast() const
  {
    return (firstElement == lastElement);
  }
private:
  long int max;
  long int min;
  long int positiveCount;
  long int negativeCount;
  long int evenSum;
  long int oddSum;
  long int elementCount;
  long int elementSum;
  long int firstElement;
  long int lastElement;
  bool FirstEqualLast;
};

std::ostream & operator<<(std::ostream & out, const MyFunctor & functor)
{
  std::cout.precision(1);
  return out << "Max: " << functor.getMax() << "\n"
    << "Min: " << functor.getMin() << "\n"
    << "Mean: " << std::setprecision(1) << std::fixed << functor.getMean() << "\n"
    << "Positive: " << functor.getPositives() << "\n"
    << "Negative: " << functor.getNegatives() << "\n"
    << "Odd Sum: " << functor.getOddSum() << "\n"
    << "Even Sum: " << functor.getEvenSum() << "\n"
    << "First/Last Equal: " << (functor.isFirstEqualLast() ? "yes" : "no");
}

int main()
{
  const static int SUCCESS = 0;
  const static int ERROR = 1;

  try
  {
    MyFunctor functor;
    functor = std::for_each(std::istream_iterator<long int>(std::cin), std::istream_iterator<long int>(), functor);
    if (!std::cin)
    {
      if (!std::cin.eof())
      {
        std::cerr << "Invalid input: you must enter only integet digits!\n";
        return ERROR;
      }
    }
    if (!functor.empty())
    {
      std::cout << functor << "\n";
    }
    else
    {
      std::cout << "No Data\n";
    }
  }
  catch (...)
  {
    std::cerr << "Exception!\n";
    return ERROR;
  }
  return SUCCESS;
}
