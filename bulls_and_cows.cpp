#include <iostream>
#include <string>
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
int main() 
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));
    const size_t len = 4; 
    string pc = generateRandomNum(len) ;
    string player;

    cout<<pc;


    return 0;
}

