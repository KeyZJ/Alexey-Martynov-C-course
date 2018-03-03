#include "DataStruct.hpp"

#include <iostream>
#include <string>
#include <algorithm>

const char DELIMITER = ',';
const int MAXIMUM = 5;
const int MININUM = -5;

bool operator<(const DataStruct & lhs, const DataStruct & rhs)
{
  if (lhs.key1 == rhs.key1)
  {
    if (lhs.key2 == rhs.key2)
    {
      return lhs.str.size() < rhs.str.size();
    }
    else
    {
      return lhs.key2 < rhs.key2;
    }
  }
  else
  {
    return lhs.key1 < rhs.key1;
  }
}

std::istream & operator>>(std::istream & in, DataStruct & data)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    std::string inStr;
    std::getline(in, inStr);
    int inKey1 = 0;
    int inKey2 = 0;

    std::string::iterator stop = inStr.begin();
    int count = 2;
    for (std::string::iterator it = inStr.begin(); it != inStr.end(); ++it)
    {
      if (*it == ',')
      {
        --count;
        if (count == 0)
        {
          stop = it;
          break;
        }
      }
    }
    inStr.erase(remove_if(inStr.begin(), stop, isspace), stop);

    if (inStr[0] == '-')
    {
      inKey1 = std::stoi(inStr.substr(0, 2));
      if ((inKey1 < MININUM) || (inKey1 > MAXIMUM))
      {
        throw std::runtime_error("Invalid input: digit must me -5 < digit < 5 !");
      }
      data.key1 = inKey1;
      if (inStr[2] != DELIMITER)
      {
        throw std::runtime_error("Invalid input: wrong delimiter, must be ',' !");
      }
      if (inStr[3] == '-')
      {
        inKey2 = std::stoi(inStr.substr(3, 5));
        if ((inKey2 < MININUM) || (inKey2 > MAXIMUM))
        {
          throw std::runtime_error("Invalid input: digit must me -5 < digit < 5 !");
        }
        data.key2 = inKey2;
        if (inStr[5] != DELIMITER)
        {
          throw std::runtime_error("Invalid input: wrong delimiter, must be ',' !");
        }
        inStr.erase(0, 6);
      }
      else
      {
        inKey2 = std::stoi(inStr.substr(3, 4));
        if ((inKey2 < MININUM) || (inKey2 > MAXIMUM))
        {
          throw std::runtime_error("Invalid input: digit must me -5 < digit < 5 !");
        }
        data.key2 = inKey2;
        if (inStr[4] != DELIMITER)
        {
          throw std::runtime_error("Invalid input: wrong delimiter, must be ',' !");
        }
        inStr.erase(0, 5);
      }
    }
    else
    {
      inKey1 = std::stoi(inStr.substr(0, 1));
      if ((inKey1 < MININUM) || (inKey1 > MAXIMUM))
      {
        throw std::runtime_error("Invalid input: digit must me -5 < digit < 5 !");
      }
      data.key1 = inKey1;
      if (inStr[1] != DELIMITER)
      {
        throw std::runtime_error("Invalid input: wrong delimiter, must be ',' !");
      }
      if (inStr[2] == '-')
      {
        inKey2 = std::stoi(inStr.substr(2, 4));
        if ((inKey2 < MININUM) || (inKey2 > MAXIMUM))
        {
          throw std::runtime_error("Invalid input: digit must me -5 < digit < 5 !");
        }
        data.key2 = inKey2;
        if (inStr[4] != DELIMITER)
        {
          throw std::runtime_error("Invalid input: wrong delimiter, must be ',' !");
        }
        inStr.erase(0, 5);
      }
      else
      {
        inKey2 = std::stoi(inStr.substr(2, 3));
        if ((inKey2 < MININUM) || (inKey2 > MAXIMUM))
        {
          throw std::runtime_error("Invalid input: digit must me -5 < digit < 5 !");
        }
        data.key2 = inKey2;
        if (inStr[3] != DELIMITER)
        {
          throw std::runtime_error("Invalid input: wrong delimiter, must be ',' !");
        }
        inStr.erase(0, 4);
      }
    }
    data.str = inStr;
    if (in.eof())
    {
      std::cout << "in.eof()\n";
      return in;
    }
  }
  return in;
}

std::ostream & operator<<(std::ostream & out, const DataStruct & data)
{
  return out << data.key1 << DELIMITER << data.key2 << DELIMITER << data.str;
}
