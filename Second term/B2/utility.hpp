#include <iostream>

namespace utility
{
  template<typename T>
  void print(const T & container)
  {
    for (typename T::const_iterator it = container.cbegin(); it != container.end(); ++it)
    {
      std::cout << *it << "\n";
    }
  }

  bool isAllowedPunctuation(char c);
  bool isHyphen(char c);
  bool isDash(std::string str);
  bool notAllowedPunctuationBeforeDash(char c);
  bool isPlus(char c);
}
