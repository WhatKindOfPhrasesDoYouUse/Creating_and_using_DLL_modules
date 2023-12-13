#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <Windows.h>
#include <tchar.h>
#include "lib/StaticLib.h"
#include "dll/DynamicLib.h"

typedef HRESULT(CALLBACK* LPFNDLLFUNC1)(DWORD, UINT*);

HRESULT LoadAndCallSomeFunction(DWORD dwParam1, UINT* puParam2);

extern "C" __declspec(dllexport) int fibonacci(int num);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Static-linking" << "\n";
    std::cout << fibonacci(5) << "\n";
    DWORD dwParam1 = 42;
    UINT uParam2;
    HRESULT hr = LoadAndCallSomeFunction(dwParam1, &uParam2);
    if (SUCCEEDED(hr)) {
        std::cout << "Dll return: " << uParam2 << std::endl;
    } else {
        std::cerr << "Не удалось вызвать dll. Код ошибки: " << hr << std::endl;
    }
    int counter = 0;
    std::thread inputThread(setLastKeys);
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::deque<char> keys = getLastKeys();
        std::cout << "Последние 10 клавиш: ";
        for (char key : keys) {
            std::cout << key << " ";
            counter++;
        }
        if (counter == 10) {
            break;
        }
        std::cout << std::endl;
    }
    inputThread.join();
    return 0;
}

HRESULT LoadAndCallSomeFunction(DWORD dwParam1, UINT* puParam2) {
    HINSTANCE hDLL = LoadLibrary("DynamicLib.dll");
    if (hDLL != NULL) {
        LPFNDLLFUNC1 lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "DLLFunc1");
        if (lpfnDllFunc1 != NULL) {
            return lpfnDllFunc1(dwParam1, puParam2);
        } else {
            FreeLibrary(hDLL);
            return ERROR_PROC_NOT_FOUND;
        }
    } else {
        return ERROR_DLL_NOT_FOUND;
    }
}
