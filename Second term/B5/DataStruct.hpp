#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP

#include <string>
#include <iosfwd>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

bool operator<(const DataStruct & lhs, const DataStruct & rhs);
std::istream & operator>>(std::istream & in, DataStruct & data);
std::ostream & operator<<(std::ostream & out, const DataStruct & data);

#endif
