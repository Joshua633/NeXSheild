#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Lock {
private:
    static string username;
    static string password;
public:
    bool check(string usr, string pass) {
        return (usr == username && pass == password);
    }
};

string Lock::username = "Joshua";
string Lock::password = "Eakamjot";

string getHiddenPassword() {
    string pass = "";
    char ch;

    while (true) {
        ch = _getch(); 

        if (ch == 13) { 
            cout << endl;
            break;
        }
        else if (ch == 8) {
            if (pass.length() > 0) {
                pass.erase(pass.length() - 1, 1);
                cout << "\b \b";
            }
        }
        else {
            pass += ch;
            cout << "*";
        }
    }
    return pass;
}

int main() {
    Lock L;
    int count = 3;
    bool ok = false;

    while (!ok) {
        string name, password;

        cout << "\nEnter your username: ";
        getline(cin, name);   // No skip now

        cout << "Enter your password: ";
        password = getHiddenPassword();

        ok = L.check(name, password);
        count--;

        if (!ok) {
            cout << "\nWrong username or password! ";
            cout << count << " chance(s) left.\n";
        }

        if (count == 0)
            return 0;
    }

    cout << "\nHI";
    return 0;
}

