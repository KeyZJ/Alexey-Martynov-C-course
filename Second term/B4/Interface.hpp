#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Book.hpp"
#include <vector>
#include <map>
#include <iosfwd>

std::istream & operator>>(std::istream & is, Book::recordType & record);

class Interface
{
public:
  typedef std::pair<std::string, Book::iterator> bookmarkType;
  typedef std::map<std::string, Book::iterator> bookmarksListType;
  typedef bookmarksListType::iterator iterator;
  Interface();
  void readCommand();
  void show(std::string markName);
  void add(Book::recordType record);
  void addWithBookmark(std::string markName, std::string number, std::string name);
  void storeBookmark(std::string markName, std::string newMarkName);
  void insertBefore(std::string markName, Book::recordType record);
  void insertAfter(std::string markName, Book::recordType record);
  void move(std::string markName, Book::difference_type stepNumber);
  void moveFirst(std::string markName);
  void moveLast(std::string markName);
  void erase(std::string markName);
private:
  bookmarksListType bookmarks_;
  Book book_;
};

#endif
