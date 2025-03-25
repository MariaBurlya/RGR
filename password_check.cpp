#include <iostream>
#include <string>

using namespace std;

bool check_password(){
    const string correct_pass = "12345";
    const int max_attempts = 3;
    string input_password;

    for (int attempts = 0; attempts < max_attempts; ++attempts) {
        cout << "Введите пароль (осталось попыток: " << (max_attempts - attempts) << "): ";
        cin >> input_password;

        if (input_password == correct_pass) {
            return true;
        }
        else {
            cout << "Пароль неверный!" << endl;
        }
    }

    cout << "Попытки исчерпаны. В доступе отказано" << endl;
    return false;
}