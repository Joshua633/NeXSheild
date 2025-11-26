#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

int main() {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    PROCESSENTRY32 pe;
    pe.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(snap, &pe)) {
        do {
            std::cout << pe.szExeFile << " (PID: " << pe.th32ProcessID << ")\n";
        } while (Process32Next(snap, &pe));
    }

    CloseHandle(snap);
    return 0;
}
