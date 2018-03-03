#include "read.hpp"
#include "utility.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstddef>

void read(std::vector<std::string> & data, std::string::size_type currentLineWidth)
{
  while (true)
  {
    std::string inText;
    std::getline(std::cin, inText);
    if (std::cin.fail())
    {
      if (std::cin.eof())
      {
         break;
      }
      else
      {
         throw std::runtime_error("Invalid input: you must enter string!");
      }
    }

    if (inText.length() > currentLineWidth)
    {
       throw std::runtime_error("Invalid input: string is too big!");
    }
    else if (isspace(inText.at(0)) != 0 && (inText.size() == 1))
    {
      return;
    }
    else if (inText.size() == 0)
    {
      return;
    }

    std::string tmp = inText;
    tmp.erase(remove_if(tmp.begin(), tmp.end(), isspace), tmp.end());
    std::string dash = "---";
    
    if (utility::isAllowedPunctuation(tmp.front()) && isdigit(*(++tmp.begin())))
    {
      throw std::runtime_error("Invalid input: first character of a line can't be an punctuation mark or hyphen!");
    }
    else if ( (utility::isAllowedPunctuation(tmp.front()) || utility::isHyphen(tmp.front()) || utility::isPlus(tmp.front())) 
      && (!isdigit(*(++tmp.begin()))) )
    {
      throw std::runtime_error("Invalid input: first character of a line can't be an punctuation mark or hyphen!");
    }
    else if (std::any_of(tmp.begin(), tmp.end(), [](char c)
    {
      return !std::isalnum(c) && !std::isspace(c) && !utility::isAllowedPunctuation(c) && !utility::isHyphen(c) & !utility::isPlus(c);
    }))
    {
      throw std::runtime_error("Invalid input: unknown character!");
    }
    else if (std::adjacent_find(tmp.begin(), tmp.end(), [](char a, char b)
    {
      return (utility::isAllowedPunctuation(a) && utility::isAllowedPunctuation(b)) || (utility::isAllowedPunctuation(a) && utility::isHyphen(b)) 
        || (utility::isHyphen(a) && utility::isAllowedPunctuation(b)) || (utility::isHyphen(a) && utility::isHyphen(b));
    }) != tmp.end())
    {
      if (tmp.find("----") != std::string::npos)
      {
        throw std::runtime_error("Invalid input: two or more punctuation marks in a row!");
      }
      else if (tmp.find(dash) != std::string::npos)
      {
        size_t dashPosition = tmp.find(dash);
        char checkFront = tmp.at(dashPosition - 1);
        if (utility::notAllowedPunctuationBeforeDash(checkFront))
        {
          throw std::runtime_error("Invalid input: only comma can be before dash!");
        }
        if (!(dashPosition + 3 >= tmp.size()))
        {
          char checkBack = tmp.at(dashPosition + 3);
          if (utility::isAllowedPunctuation(checkBack))
          {
            throw std::runtime_error("Invalid input: after dash can't be any punctuation!");
          }
        }
      }
      else
      {
        throw std::runtime_error("Invalid input: two or more punctuation marks in a row!");
      }
    }
    std::string::iterator foundIt = std::find(inText.begin(), inText.end(), ' ');
    std::string::iterator lastFoundIt = inText.begin();
    std::string::difference_type longestWord = 0;
    std::string::difference_type maxWordLenght = 20;

    while (foundIt != inText.end())
    {
      std::string::difference_type newWord = std::distance(lastFoundIt, foundIt);
      if (newWord > longestWord)
      {
        longestWord = newWord;
      }
      lastFoundIt = foundIt;
      foundIt = std::find(foundIt + 1, inText.end(), ' ');
    }
    if ((longestWord > maxWordLenght) || (std::distance(lastFoundIt, inText.end()) > maxWordLenght))
    {
      throw std::runtime_error("Invalid input: word can't be more than 20 characters!");
    }

    data.push_back(inText);
  }
}
