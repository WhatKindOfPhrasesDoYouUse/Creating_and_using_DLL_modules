#include <iostream>
#include "StaticLib.h"
#include "windows.h"

#pragma comment(lib, "ws2_32.lib");

int fibonacci(int num) {
    if (num == 1 || num == 2) {
        return 1;
    } else {
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
}