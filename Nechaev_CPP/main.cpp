#include <Windows.h>

#include "Person.h"

void main() 
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person<string, string, string, string, string> chelovek1{ "brawl stars", "Leon", 17, "4444 666666", 0.91, "T-BankUser333", "абоба" };
    Person<int, string, string, string, int> chelovek2{ 0, "Zloy David V Mute.", 10, "0000 000000", 503.32, "Inoagent", 52 };
    Person<double, string, string, int, int> chelovek3{ 36.6, "alex shopkeeper", 18, "4444 666666", 2000.02, 33, 64 };
    
    
}