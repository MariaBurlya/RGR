#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <windows.h>

using namespace std;

map<char, int> symbol_encrypt_map() { // для работы шифра с символами
    return {
        {'!', 68}, {'@', 69}, {'#', 70}, {'$', 71}, {'%', 72}, {'^', 73}, 
        {'&', 74}, {'*', 75}, {'(', 76}, {')', 77}, {'-', 78}, {'_', 79}, 
        {'+', 80}, {'=', 81}, {'"', 82}, {'№', 83}, {';', 84}, {':', 85}, 
        {'?', 86}, {'[', 87}, {']', 88}, {'{', 89}, {'}', 90}, {'<', 91}, 
        {'>', 92}, {'|', 93}, {'/', 94}
    };
}

map<int, char> symbol_decrypt_map() {
    return {
        {68, '!'}, {69, '@'}, {70, '#'}, {71, '$'}, {72, '%'}, {73, '^'}, 
        {74, '&'}, {75, '*'}, {76, '('}, {77, ')'}, {78, '-'}, {79, '_'}, 
        {80, '+'}, {81, '='}, {82, '"'}, {83, '№'}, {84, ';'}, {85, ':'}, 
        {86, '?'}, {87, '['}, {88, ']'}, {89, '{'}, {90, '}'}, {91, '<'}, 
        {92, '>'}, {93, '|'}, {94, '/'}
    };
}

string encrypt_A1Z26(const string& text) {
    stringstream encrypted; // строковый поток для хранения зашифрованного текста
    auto symbol_map = symbol_encrypt_map();

    for (char c : text) {
        if (isalpha(c)) { // проверка является ли символ буквой
            if (isupper(c)) { // проверка на верхний регистр
                int position = c - 'A' + 1; // A1Z26 (от 1 до 26)
                encrypted << position << " ";
            }
            else if (islower(c)) {
                int position = c - 'a' + 1;
                encrypted << position << " ";
            }
        }
        else if (c >= 'А' && c <= 'Я') { // А1Я32 (от 1 до 32)
            int position = c - 'А' + 1;
            encrypted << position + 26 << " "; // сдвиг на 26
        }
        else if (c >= 'а' && c <= 'я') {
            int position = c - 'а' + 1;
            encrypted << position + 32 << " ";
        }
        else if (symbol_map.count(c)) {
            encrypted << symbol_map[c] << " ";
        }
        else if (isdigit(c)) {
            encrypted << (c - '0' + 93) << " ";
        }
    }
    return encrypted.str();
}

string decrypt_A1Z26(const string& encrypted) {
    stringstream decrypted;
    string symbol;
    stringstream ss(encrypted); // поток для обработки зашифрованного текста
    auto rev_decrypt_map = symbol_decrypt_map();

    while (ss >> symbol) { // проходим по каждому символу в тексте
        if (isdigit(symbol[0])) { // проверка, что символ является числом
            int num = stoi(symbol); // преобразование символа в целое число
            if (num >= 1 && num <= 26) {
                // Дешифровка A1Z26
                char ch = 'A' + num - 1; // для английского алфавита
                decrypted << ch;
            }
            else if (num > 27 && num <= 32) {
                // Дешифровка А1Я32
                char ch = 'А' + (num - 27); // для русского алфавита
                decrypted << ch;
            }
            else if (num >= 33 && num <= 58) {
                char ch = 'а' + (num - 33);
                decrypted << ch;
            }
            else if (num >= 93 && num <= 102) {
                decrypted << (num - 93 + '0');
            }
            else if (rev_decrypt_map.count(num)) {
                decrypted << rev_decrypt_map[num];
            }
        }
        else {
            decrypted << symbol; // другие символы
        }
    }
    return decrypted.str();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string text;
    string encrypted, decrypted;
    cout << "Enter text: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Are you dolbaeb?" << endl;
        return 1;
    }

    encrypted = encrypt_A1Z26(text); 
    cout << "Encrypted text: " << encrypted << endl;

    decrypted = decrypt_A1Z26(encrypted);
    cout << "Decrypted text: " << decrypted << endl;
    return 0;
}
