#ifndef PROCESSINGQUEUE_HPP
#define PROCESSINGQUEUE_HPP

#include "QueueWithPriority.hpp"
#include <istream>

void readCommand();
std::istream & operator>>(std::istream & ism, ElementPriority & priority);

#endif
