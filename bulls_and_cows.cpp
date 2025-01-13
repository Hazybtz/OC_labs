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

int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const vector<char> data = {'0','1','2','3','4','5','6','7','8','9'};
    const size_t len = 4; 

    srand(time(0));
    string pc = generateRandomNum(len) ;
    string player;
    cout << "Введите предполагаемое число: ";
    cin >> player;
    while(!(isNum(player, data)) || player.length() != len)
    {
        cout << "ошибка ввода! Попробуйте еще раз.\n";
        cout << "Введите предполагаемое четырехзначное число: ";
        cin >> player;
    }
    
    

    return 0;
}

