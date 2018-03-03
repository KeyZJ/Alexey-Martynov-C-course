#include "format.hpp"
#include "utility.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

void eraseNonSpaceWhitespaces(std::string & str)
{
  str.erase(std::remove_if(str.begin(), str.end(), [](char c)
  {
    return std::isspace(c) && (c != ' ');
  }), str.end());
}

void eraseDuplicateSpaces(std::string & str)
{
  str.erase(std::unique(str.begin(), str.end(), [](char a, char b)
  {
    return (a == ' ') && (b == ' ');
  }), str.end());
}

void eraseSpaceBeforePunctuationMark(std::string & str)
{
  for (std::string::iterator it = str.begin(); it != str.end(); ++it)
  {
    std::string::iterator foundIt = std::adjacent_find(it, str.end(), [](char a, char b)
    {
      return std::isspace(a) && (utility::isAllowedPunctuation(b) || utility::isHyphen(b));
    });
    if (foundIt != str.end())
    {
      it = str.erase(foundIt);
    }
  }
}

void eraseSpaceAfterHyphen(std::string & str)
{
  for (std::string::iterator it = str.begin(); it != str.end(); ++it)
  {
    std::string::iterator foundIt = std::adjacent_find(it, str.end(), [](char a, char b)
    {
      return utility::isHyphen(a) && std::isspace(b);
    });
    if (foundIt != str.end())
    {
      it = str.erase(++foundIt);
    }
  }
}

void addSpacesNearDash(std::string & str)
{
  for (std::string::iterator it = str.begin(); it != str.end(); ++it)
  {
    std::string::iterator foundIt = std::search_n(it, str.end(), 3, '-');
    if (foundIt != str.end())
    {
      it = str.insert(foundIt++, ' ');
      it = str.insert(foundIt + 3, ' ');
    }
  }
}

void addSpaceAfterPunctuationMark(std::string & str)
{
  for (std::string::iterator it = str.begin(); it != str.end(); ++it)
  {
    char decimalSeparator = std::use_facet< std::numpunct<char> >(std::cout.getloc()).decimal_point();

    std::string::iterator foundIt = std::adjacent_find(it, str.end(),
      [decimalSeparator](char a, char b)
    {
      return utility::isAllowedPunctuation(a) && !std::isspace(b) && !(a == decimalSeparator && std::isdigit(b));
    });
    if (foundIt != str.end())
    {
      it = str.insert(++foundIt, ' ');
    }
  }
}

void format(std::vector<std::string> & data)
{
  for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); ++it)
  {
    eraseNonSpaceWhitespaces(*it);
    eraseDuplicateSpaces(*it);

    addSpaceAfterPunctuationMark(*it);
    eraseSpaceBeforePunctuationMark(*it);
    eraseSpaceAfterHyphen(*it);
    addSpacesNearDash(*it);
    
    eraseDuplicateSpaces(*it);
  }
}
