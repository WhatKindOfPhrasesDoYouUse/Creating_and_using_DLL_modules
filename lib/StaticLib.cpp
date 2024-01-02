#include <iostream>
#include "StaticLib.h"
#include "windows.h"

int fibonacci(int num) {
    if (num < 1) {
        return num;
    }
    int a = 0, b = 1, result = 0;
    for (int i = 2; i <= num; ++i) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}
