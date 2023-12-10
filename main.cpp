#include <iostream>
#include "lib/StaticLib.h"
#include "dll/DynamicLib.h"
#include <thread>
#include <mutex>
#include <deque>
#include <Windows.h>
#include <sec_api/tchar_s.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Static-linking" << std::endl;
    std::cout << fibonacci(10) << std::endl;
    std::cout << fibonacci(22) << std::endl;
    std::cout << "Dynamic-linking" << std::endl;
    std::thread inputThread(setLastKeys);
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::deque<char> keys = getLastKeys();
        std::cout << "Последние 10 клавиш: ";
        for (char key : keys) {
            std::cout << key << " ";
        }
        std::cout << std::endl;
    }
    inputThread.join();
    return 0;
}
