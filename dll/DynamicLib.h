#ifndef DYNAMIC_LIB_H
#define BYNAMIC_LIB_H

#include <mutex>
#include <deque>

extern std::deque<char> lastKeys;
extern std::mutex mutex;

void setLastKeys();
std::deque<char> getLastKeys();

#endif