#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
using namespace std;

string generateRandomNum(size_t len) 
{
    string number;
    while (number.length() < len) 
    {
        char digit = '0' + rand() % 10;
        if (!(number.find(digit) != string::npos || (number.length() == 0 && digit == '0'))) 
        {
            number += digit;
        }
    }
    return number;
}

bool isNum(string player, vector<char> data)
{
    for (size_t i = 0; i < player.length(); i++) 
    {
        auto res = find(begin(data), end(data), player[i]);
        if (res == end(data)) {
            return false;
        }
    }
    return true;
}

void countBullsAndCows(const string& pc, const string& player, int& bulls, int& cows) 
{
    bulls = 0;
    cows = 0;
    for (size_t i = 0; i < pc.length(); i++) 
    {
        if (player[i] == pc[i]) 
        {
            bulls++;
        } 
        else if (pc.find(player[i]) != string::npos) 
        {
            cows++;
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    
    const vector<char> data = {'0','1','2','3','4','5','6','7','8','9'};
    const size_t len = 4; 

    string pc = generateRandomNum(len) ;
    string player;
    int attempts = 0;
    cout << "Игра 'Быки и коровы'!\n";
    cout << "Компьютер загадал число из 4 неповторяющихся цифр.\n";
    cout << "Ваша задача — угадать это число.\n";
    cout << "Кол-во коров — это сколько цифр угадано без совпадений с их позициями.\n";
    cout << "Кол-во быков — это сколько цифр угадано вплоть до позиции.\n";
    cout << "Чтобы предварительно завершить игру, введите 'q'.\n";

    while(true)
    {
        cout << "\nВведите предполагаемое число: ";
        cin >> player;
        if (player == "q") return 0;

        while(!(isNum(player, data)) || player.length() != len)
        {
            cout << "Ошибка ввода! Попробуйте еще раз.\n";
            cout << "Введите предполагаемое четырехзначное число: ";
            cin >> player;
            if (player == "q") return 0;
            cout << endl;
        }

        attempts++;
        int bulls = 0, cows = 0;
        countBullsAndCows(pc, player, bulls, cows);
        
        if (bulls == len) 
        {
            cout << "Поздравляем! Вы угадали число " << pc << " за " << attempts << " попыток.\n";
            break;
        } 
        else 
        {
            cout << "Быки: " << bulls << ", Коровы: " << cows << "\n";
        }
    }
    

    return 0;
}

