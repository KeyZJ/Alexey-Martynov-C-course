#include "Interface.hpp"
#include "Book.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

std::istream & operator>>(std::istream & is, Book::recordType & record)
{
  const char boundChar = '\"';

  std::istream::sentry senrty(is);
  if (senrty)
  {
    is >> std::ws >> record.first;
    char c;
    is >> c;
    if (is.fail())
    {
      return is;
    }
    if (c != boundChar)
    {
      is.setstate(std::istream::failbit);
      return is;
    }
    std::string tmp;
    std::getline(is, tmp);
    tmp = tmp.substr(0, tmp.rfind(boundChar));
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\\'), tmp.end);
    record.second = tmp;
  }
  return is;
}


Interface::Interface() :
  book_()
{
  bookmarks_.emplace("current", book_.end());
}

void Interface::readCommand()
{
  static const std::string invalidCommand = "<INVALID COMMAND>";
  while (std::cin)
  {
    std::string input;
    std::getline(std::cin, input);
    std::istringstream line(input);
    if (std::cin.fail())
    {
      if (std::cin.eof())
      {
        break;
      }
      else
      {
        throw std::runtime_error("Invalid input!");
      }
    }
    else
    {
      std::string inputWord, tmp;
      line >> inputWord;
      if (inputWord == "add")
      {
        Book::recordType record;
        line >> record;
        if (!line.fail())
        {
          add(record);
        }
        else
        {
          std::cout << invalidCommand << "\n";
        }
      }
      else if (inputWord == "store")
      {
        std::string markName, newMarkName;
        line >> markName;
        line >> newMarkName;;
        storeBookmark(markName, newMarkName);
      }
      else if (inputWord == "insert")
      {
        std::string markName;
        line >> tmp;
        line >> markName;
        Book::recordType record;
        line >> record;
        if (!line.fail())
        {
          if (tmp == "before")
          {
            insertBefore(markName, record);
          }
          else if (tmp == "after")
          {
            insertAfter(markName, record);
          }
        }
        else
        {
          std::cout << invalidCommand << "\n";
        }
      }
      else if (inputWord == "delete")
      {
        line >> tmp;
        erase(tmp);
      }
      else if (inputWord == "show")
      {
        line >> tmp;
        show(tmp);
      }
      else if(inputWord == "move")
      {
        line >> tmp;
        std::string keyWord;
        line >> keyWord;
        if (keyWord == "first")
        {
          moveFirst(tmp);
        }
        else if (keyWord == "last")
        {
          moveLast(tmp);
        }
        else
        {
          std::istringstream stream(keyWord);
          Book::difference_type steps;
          stream >> steps;
          if (stream.fail())
          {
            std::cout << "<INVALID STEP>\n";
          }
          move(tmp, steps);
        }
      }
      else
      {
        std::cout << invalidCommand << "\n";
      }
    }
  }
}

void Interface::show(std::string markName)
{
  Interface::iterator tmp = bookmarks_.find(markName);
  if (tmp != bookmarks_.end())
  {
    if (tmp->second != book_.end())
    {
      std::cout << tmp->second->first << " " << tmp->second->second << std::endl;
    }
    else
    {
      std::cout << "<EMPTY>\n";
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>\n";
  }
}

void Interface::storeBookmark(std::string markName, std::string newMarkName)
{
  Interface::iterator it = bookmarks_.find(markName);
  if (it != bookmarks_.end())
  {
    if (!(bookmarks_.emplace(newMarkName, it->second).second))
    {
      bookmarks_[newMarkName] = it->second;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>\n";
  }
}

void Interface::addWithBookmark(std::string markName, std::string number, std::string name)
{
  Book::recordType record = std::make_pair(number, name);
  Book::iterator it = book_.add(record);
  bookmarks_.emplace(markName, it);
}

void Interface::insertBefore(std::string markName, Book::recordType record)
{
  Interface::iterator position = bookmarks_.find(markName);
  if (position != bookmarks_.end())
  {
    Book::iterator it = book_.addBefore(position->second, record);
    if (bookmarks_.size() == 1)
    {
      position->second = it;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>\n";
  }
}

void Interface::insertAfter(std::string markName, Book::recordType record)
{
  Interface::iterator position = bookmarks_.find(markName);
  if (position != bookmarks_.end())
  {
    Book::iterator it = book_.addAfter(position->second, record);
    if (bookmarks_.size() == 1)
    {
      position->second = it;
    }
  }
  else
  {
    std::cout << "<INVALID BOOKMARK>\n";
  }
}

void Interface::add(Book::recordType record)
{
  if (book_.empty())
  {
    Book::iterator it = book_.add(record);
    Interface::iterator currentPosition = bookmarks_.find("current");
    currentPosition->second = it;
  }
  else
  {
    book_.add(record);
  }
}

void Interface::moveFirst(std::string markName)
{
  Interface::iterator position = bookmarks_.find(markName);
  position->second = book_.begin();
}

void Interface::moveLast(std::string markName)
{
  Interface::iterator position = bookmarks_.find(markName);
  position->second = std::prev(book_.end());
}

void Interface::move(std::string markName, Book::difference_type stepNumber)
{
  Interface::iterator position = bookmarks_.find(markName);
  if (position != bookmarks_.end())
  {
    for (Book::difference_type count = 0; count < std::abs(stepNumber); ++count)
    {
      (stepNumber > 0) ? ++position->second : --position->second;
    }
  }
}

void Interface::erase(std::string markName)
{
  if (!book_.empty())
  {
    Interface::iterator position = bookmarks_.find(markName);
    Book::iterator oldIt = position->second;
    position->second = book_.erase(position->second);
    if (position->second == book_.end())
    {
      std::advance(position->second, -1);
    }
    for (Interface::iterator it = bookmarks_.begin(); it != bookmarks_.end(); ++it)
    {
      if (it->second == oldIt)
      {
        it->second = position->second;
      }
    }
  }
}
