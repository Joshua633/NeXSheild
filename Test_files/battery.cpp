#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void showBatteryInfo() {
    SYSTEM_POWER_STATUS s;

    if (GetSystemPowerStatus(&s)) {
        cout << "==============================\n";

        cout << "AC Line Status : ";
        if (s.ACLineStatus == 0) cout << "Offline";
        else if (s.ACLineStatus == 1) cout << "Online";
        else cout << "Unknown";
        cout << endl;

        cout << "Battery %      : ";
        if (s.BatteryLifePercent == 255)
            cout << "Unknown";
        else
            cout << (int)s.BatteryLifePercent << "%";
        cout << endl;

        cout << "Battery Status : ";
        if (s.BatteryFlag & 8) cout << "Charging";
        else if (s.BatteryFlag & 1) cout << "High";
        else if (s.BatteryFlag & 2) cout << "Low";
        else if (s.BatteryFlag & 4) cout << "Critical";
        else cout << "Unknown";
        cout << endl;

        cout << "Time Left      : ";
        if (s.BatteryLifeTime == (DWORD)-1)
            cout << "Unknown";
        else
            cout << s.BatteryLifeTime << " sec";
        cout << endl;

        cout << "==============================\n";
    }
}

int main() {
    while (true) {
        system("cls");   // Clear screen
        showBatteryInfo();
        Sleep(1000);     // Sleep 1 second (Windows API)
    }
    return 0;
}

