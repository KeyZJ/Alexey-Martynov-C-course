#include "processingQueue.hpp"
#include "QueueWithPriority.hpp"

#include <iostream>
#include <string>

std::istream & operator>>(std::istream & is, ElementPriority & priority)
{
  std::istream::sentry sentry(is);
  if (sentry)
  {
    std::string value;
    is >> value;
    if (value == "low")
    {
      priority = LOW;
    }
    else if (value == "normal")
    {
      priority = NORMAL;
    }
    else if (value == "high")
    {
      priority = HIGH;
    }
    else
    {
      is.setstate(std::istream::failbit);
      return is;
    }
  }
  return is;
}

void readCommand()
{
  static const std::string error_message = "<INVALID COMMAND>";
  QueueWithPriority<QueueElement<std::string>> queue;

  while (std::cin)
  {
    std::string input;
    std::cin >> input;
    if (std::cin.fail())
    {
      if (std::cin.eof())
      {
        break;
      }
      else
      {
        std::cout << error_message << "\n";
      }
    }
    if (input == "add")
    {
      QueueElement<std::string> newElement;
      std::cin >> newElement.priority;
      if (std::cin.fail())
      {
        std::cout << error_message << "\n";
        break;
      }
      std::getline((std::cin >> std::ws), newElement.data);
      if (std::cin.eof())
      {
        std::cout << error_message << "\n";
      }
      queue.putElementToQueue(newElement);
    }
    else if (input == "get")
    {
      if (queue.empty())
      {
        std::cout << "<EMPTY>\n";
      }
      else
      {
        QueueElement<std::string> getElement = queue.getTopPriorityElement();
        queue.popTopPriorityElement();
        std::cout << getElement.data << "\n";
      }
    }
    else if (input == "accelerate")
    {
      queue.accelerate();
    }
    else
    {
      std::cout << error_message << "\n";
    }
  }
}
