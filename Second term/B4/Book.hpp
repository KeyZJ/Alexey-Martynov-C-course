#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <memory>
#include <list>

class Book
{
public:
  typedef std::pair<std::string, std::string> recordType;
  typedef std::list<recordType> bookType;
  typedef bookType::iterator iterator;
  typedef bookType::difference_type difference_type;
  Book();
  iterator add(recordType record);
  iterator addAfter(iterator position, recordType record);
  iterator addBefore(iterator position, recordType record);
  iterator begin();
  iterator end();
  iterator erase(iterator & position);
  void replace(recordType record);
  void goBack();
  void goForward();
  void show() const;
  bool empty() const;
private:
  bookType addressBook_;
  iterator currentRecord_;
};

#endif
