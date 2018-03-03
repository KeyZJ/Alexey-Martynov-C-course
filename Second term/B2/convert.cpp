#include "convert.hpp"

#include <string>
#include <vector>

std::vector<std::string> convert(std::vector<std::string> & source, std::string::size_type lineWidth)
{
  std::vector<std::string> newText;
  std::string largeString = "";

  for (std::vector<std::string>::iterator it = source.begin(); it != source.end(); ++it)
  {
    largeString.append(*it);
    largeString.append(" ");
  }

  std::string::size_type currentPosition = 0;
  std::string::size_type nextPosition = 0;
  std::string subString = largeString.substr(currentPosition, lineWidth + 1);

  while ((subString.length() == lineWidth + 1) && ((nextPosition = subString.rfind(' ')) != largeString.npos))
  {
    newText.push_back(largeString.substr(currentPosition, nextPosition));
    currentPosition += nextPosition + 1;
    subString = largeString.substr(currentPosition, lineWidth + 1);
  }

  if ((currentPosition != largeString.length()))
  {
    newText.push_back(largeString.substr(currentPosition, largeString.npos));
  }

  return newText;
}
