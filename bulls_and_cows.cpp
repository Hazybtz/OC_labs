#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int len = 4; 
    string pc;
    string player;

    while (true)
    {
        cout << "Введите предполагаемое число: ";
        cin >> player;
        while (player.length() != len) 
        {
            cout << "Загаданное число - четыреззначное.\nПопробуйте ввести еще раз:\n";
            cin >> player;
        }
    }


    return 0;
}

