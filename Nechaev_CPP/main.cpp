#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

double Divide(double number1, double number2)
{
    double result = number1 / number2;

    if (!number2) // number2 == 0
    {
        throw 0; // выкидываем программе исключение типа данных int
    }
    if (number2 > number1)
    {
        throw string("Знаменатель больше числителя, дубина!");
    }
    if (result == 1)
    {
        throw 1;
    }
    if (result - int(result) == 0.5) throw string("Я не люблю остаток 0.5, поэтому не дам тебе отработать этой функции, тупица");
    return result;
}

void main() 
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        cout << Divide(5, 2) << endl;
    }
    catch (const string& errorMessage)
    {
        cout << "Возникла ошибка, ты дурень: " << errorMessage << endl;
    }
    catch (const int intMessage)
    {
        if (intMessage == 0) cout << "На 0 дельить нельзя, ты дурень x2:" << intMessage << endl;
        else if (intMessage == 1) cout << "Ты вписал 2 одинаковых числа, дурень, очевидно х3, что ответ " << intMessage << endl;
        else cout << "Возникла int-овая ошибка, ты дурень x4:" << intMessage << endl;
    }
    cout << "Я работаю дальше!" << endl;

    system("pause");
}
//      Практика
// 1. 
// 2. 
// 3. 