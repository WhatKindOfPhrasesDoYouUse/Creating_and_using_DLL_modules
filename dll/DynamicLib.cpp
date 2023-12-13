#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include "DynamicLib.h"

std::deque<char> lastKeys;
std::mutex mutex;

void setLastKeys() {
    int counter = 0;
    while (counter <= 10) {
        char key;
        std::cin >> key;
        std::lock_guard<std::mutex> lock(mutex);
        if (lastKeys.size() >= 10) {
            lastKeys.pop_front();
            counter++;
        }
        lastKeys.push_back(key);
    }
}

std::deque<char> getLastKeys() {
    std::lock_guard<std::mutex> lock(mutex);
    return lastKeys;
}

