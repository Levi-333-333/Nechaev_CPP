#include <Windows.h>
#include <iostream>
#include <string>
#include <stdexcept>

#include "stack.h"

class PersonError : std::exception
{
public:
    PersonError(std::string _message)
    {
        message = _message;
    }
    const char* what() const override
    {
        return message.c_str();
    }
private:
    std::string message;
};

class Person
{
public:
    Person(std::string _name, int _age)
    {
        if (_name.length() > 3)
        {
            throw std::length_error{ "У тебя слишком длинное имя, недоумок!" };
        }

        if (!age || age > 120)
        {
            throw std::range_error{ "Неверный возраст, ты полуослик и олух!" };
        }

        name = _name;
        age = _age;
    }
    ~Person()
    {

    }
    void PrintInfo()
    {
        std::cout << "Имя: " << name << ". Возраст: " << age << std::endl;
    }
private:
    std::string name;
    unsigned int age;
};

//double Divide(double number1, double number2)
//{
//    double result = number1 / number2;
//
//    if (!number2) // number2 == 0
//    {
//        throw 0; // выкидываем программе исключение типа данных int
//    }
//    if (number2 > number1)
//    {
//        throw string("Знаменатель больше числителя, дубина!");
//    }
//    if (result == 1)
//    {
//        throw 1;
//    }
//    if (result - int(result) == 0.5) throw string("Я не люблю остаток 0.5, поэтому не дам тебе отработать этой функции, тупица");
//    return result;
//}

void main() 
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    element<int>* stack = nullptr;
    FillStack(stack);
    PrintStack(stack);
    ClearStack(stack);

    system("pause");
}