#include "utility.hpp"

namespace utility
{ 
  bool isAllowedPunctuation(char c)
  {
    const std::string punctuation{ ".,!?:;" };
    return punctuation.find(c) != std::string::npos;
  }

  bool isHyphen(char c)
  {
    return c == '-';
  }
  
  bool isDash(std::string str)
  {
    const std::string dash{ "---" };
    return str == dash;
  }

  bool notAllowedPunctuationBeforeDash(char c)
  {
    const std::string punctuation{ ".!?:;" };
    return punctuation.find(c) != std::string::npos;
  }

  bool isPlus(char c)
  {
    return c == '+';
  }
}
