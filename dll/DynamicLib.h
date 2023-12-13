#pragma once

#ifndef DYNAMIC_LIB_H
#define DYNAMIC_LIB_H

#include <mutex>
#include <deque>
#include "DynamicLib.h"

extern std::deque<char> lastKeys;
extern std::mutex mutex;

__declspec(dllexport) void setLastKeys();
__declspec(dllexport) std::deque<char> getLastKeys();

#endif