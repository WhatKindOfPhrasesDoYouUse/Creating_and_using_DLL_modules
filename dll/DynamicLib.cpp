#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

std::deque<char> lastKeys;
std::mutex mutex;

void setLastKeys() {
    while (true) {
        char key;
        std::cin >> key;
        std::lock_guard<std::mutex> lock(mutex);
        if (lastKeys.size() >= 10) {
            lastKeys.pop_front();
        }
        lastKeys.push_back(key);
    }
}

std::deque<char> getLastKeys() {
    std::lock_guard<std::mutex> lock(mutex);
    return lastKeys;
}