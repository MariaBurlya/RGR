#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << int('А') << endl;
    cout << char(49) << endl;
}