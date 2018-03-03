#ifndef QUEUE_WITH_PRIORITY_HPP
#define QUEUE_WITH_PRIORITY_HPP

#include <list>

typedef enum
{
  LOW,
  NORMAL,
  HIGH
} ElementPriority;

template< typename T>
struct QueueElement
{
  T data;
  ElementPriority priority;
};

template<typename T>
class QueueWithPriority
{
public:
  typedef QueueWithPriority<T> this_type;
  typedef T value_type;
  typedef value_type & reference;
  typedef const value_type & const_reference;
  typedef typename std::list<value_type>::iterator iterator;
  typedef typename std::list<value_type>::const_iterator const_iterator;
  typedef std::ptrdiff_t difference_type;
  typedef std::size_t size_type;

  const_reference getTopPriorityElement() const
  {
    if (!highPriorityList_.empty())
    {
      return highPriorityList_.front();
    }
    else if (!normalPriorityList_.empty())
    {
      return normalPriorityList_.front();
    }
    else if (!lowPriorityList_.empty())
    {
      return lowPriorityList_.front();
    }
    else
    {
      return *lowPriorityList_.cbegin();
    }
  }

  void popTopPriorityElement()
  {
    if (!highPriorityList_.empty())
    {
      return highPriorityList_.pop_front();
    }
    else if (!normalPriorityList_.empty())
    {
      return normalPriorityList_.pop_front();
    }
    else if (!lowPriorityList_.empty())
    {
      return lowPriorityList_.pop_front();
    }
  }

  void putElementToQueue(const_reference element)
  {
    switch (element.priority)
    {
    case HIGH:
    {
      highPriorityList_.push_back(element);
      break;
    }
    case NORMAL:
    {
      normalPriorityList_.push_back(element);
      break;
    }
    case LOW:
    {
      lowPriorityList_.push_back(element);
      break;
    }
    }
  }

  void accelerate()
  {
    highPriorityList_.splice(highPriorityList_.end(), lowPriorityList_);
  }

  bool empty() const
  {
    return (highPriorityList_.empty() && normalPriorityList_.empty() && lowPriorityList_.empty());
  }

private:
  std::list<value_type> highPriorityList_;
  std::list<value_type> normalPriorityList_;
  std::list<value_type> lowPriorityList_;
};

#endif
