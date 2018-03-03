#include "utility.hpp"
#include "read.hpp"
#include "format.hpp"
#include "convert.hpp"

#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char * argv[])
{
  std::string::size_type defaultLineWidth = 40;
  std::string::size_type currentLineWidth = 0;
  const std::string lineWidthKey{ "--line-width" };

  if (argc > 3)
  {
    throw std::invalid_argument("Invalid input: there could be only one argument '--line-width'!");
  }
  else if (argc == 1)
  {
    currentLineWidth = defaultLineWidth;
  }
  else
  {
    if (argc == 3)
    {
      std::istringstream in(argv[2]);
      if (in.fail())
      {
        throw std::invalid_argument("Invalid input:there must be an integer digit, which represents size of string in '--line-width'!");
      }
      in >> currentLineWidth;
    }
    else
    {
      throw std::invalid_argument("Invalid input: there must be an digit, which represents size of string in '--line-width'!");
    }
  }

  std::vector<std::string> data;

  try
  {
    read(data, currentLineWidth);
    format(data);
    std::vector<std::string> finalData;
    finalData = convert(data, currentLineWidth);
    utility::print(finalData);
  }
  catch (std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Unknown error!\n";
    return 2;
  }
  return 0;
}
