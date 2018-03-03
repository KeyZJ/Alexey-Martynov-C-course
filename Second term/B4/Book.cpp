#include "Book.hpp"

#include <iostream>

Book::Book() :
  addressBook_()
{
  currentRecord_ = addressBook_.end();
}

Book::iterator Book::add(recordType record)
{
  addressBook_.push_back(record);
  if (addressBook_.size() != 1)
  {
    currentRecord_ = std::prev(addressBook_.end());
  }
  else
  {
    currentRecord_ = addressBook_.begin();
  }
  return currentRecord_;
}

Book::iterator Book::addAfter(iterator position, recordType record)
{
  position = addressBook_.insert(std::next(position), record);
  return position;
}

Book::iterator Book::addBefore(iterator position, recordType record)
{
  position = addressBook_.insert(position, record);
  return position;
}

Book::iterator Book::begin()
{
  return addressBook_.begin();
}

Book::iterator Book::end()
{
  return addressBook_.end();
}

Book::iterator Book::erase(iterator & position)
{
  return addressBook_.erase(position);
}

void Book::replace(recordType record)
{
  if (currentRecord_ != addressBook_.end())
  {
    currentRecord_ = addressBook_.erase(currentRecord_++);
    currentRecord_ = addressBook_.insert(currentRecord_, record);
  }
}

void Book::goBack()
{
  if (currentRecord_ != addressBook_.begin())
  {
    --currentRecord_;
  }
}
void Book::goForward()
{
  if (std::next(currentRecord_) != addressBook_.end())
  {
    ++currentRecord_;
  }
}

void Book::show() const
{
  if (currentRecord_ != addressBook_.end())
  {
    std::cout << currentRecord_->first << " " << currentRecord_->second << std::endl;
  }
}

bool Book:: empty() const
{
  return addressBook_.empty();
}
