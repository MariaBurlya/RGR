#include <iostream>
#include <string>
#include "A1Z26.h"
#include "Bacon.h"
#include "Polibius.h"
#include "password_check.cpp"

using namespace std;

int main() {
    
    if(check_password()) {
        cout << "Добро пожаловать!" << endl;
    }

    string text, encrypted, decrypted;
    int choise;
    cout << "Введите текст для шифрования: ";
    cin >> text;
    cout << "Выберите метод шифрования" << endl;
    cout << "1 - шифр A1Z26" << endl;
    cout << "2 - шифр квадрат Полибия" << endl;
    cout << "3 - шифр Полибия" << endl;
    cin >> choise;

    switch(choise) {
        case 1:
            encrypted = A1Z26_encrypt(text);
            decrypted = A1Z26_decrypt(encrypted);
            break;
        case 2:
            encrypted = polibius_encrypt(text);
            decrypted = polibius_decrypt(encrypted);
            break;
        case 3:
            encrypted = bacon_encrypt(text);
            decrypted = bacon_decrypt(encrypted);
            break;
        default:
            cout << "Неверный выбор метода шифрования. Попробуйте снова";
    }

    cout << "Исходный текст: " << text << endl;
    cout << "Зашифрованный текст: " << encrypted << endl;
    cout << "Дешифрованный текст: " << decrypted << endl;

    return 0;
}
