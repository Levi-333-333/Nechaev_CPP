#include <iostream>
#include <Windows.h>

// Ф-я, принимающая в качестве третьего параметра указатель на функцию, которая выступает в виде лямбда-выражения
void Calc(int number1, int number2, int (*operation)(int, int))
{
    std::cout << "Результат операции: " << operation(number1, number2) << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto sum{ [](int number1, int number2) {return number1 + number2; } };
    auto sub{ [](int number1, int number2) {return number1 - number2; } };
    auto mul{ [](int number1, int number2) {return number1 * number2; } };
    auto div{ [](int number1, int number2) {return number1 / number2; } };

    int userNumber1;
    int userNumber2;
    int userChoice;

    do
    {
        std::cout << "Введите цифру от 1 до 4, где:\n1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление" << std::endl;
        std::cin >> userChoice;
        switch (userChoice)
        {
        case 1:
            std::cout << "Введите первое число: ";
            std::cin >> userNumber1;
            std::cout << std::endl;

            std::cout << "Введите второе число: ";
            std::cin >> userNumber2;
            std::cout << std::endl;

            Calc(userNumber1, userNumber2, sum);
            break;
        case 2:
            std::cout << "Введите первое число: ";
            std::cin >> userNumber1;
            std::cout << std::endl;

            std::cout << "Введите второе число: ";
            std::cin >> userNumber2;
            std::cout << std::endl;

            Calc(userNumber1, userNumber2, sub);
            break;
        case 3:
            std::cout << "Введите первое число: ";
            std::cin >> userNumber1;
            std::cout << std::endl;

            std::cout << "Введите второе число: ";
            std::cin >> userNumber2;
            std::cout << std::endl;

            Calc(userNumber1, userNumber2, mul);
            break;
        case 4:
            std::cout << "Введите первое число: ";
            std::cin >> userNumber1;
            std::cout << std::endl;

            std::cout << "Введите второе число: ";
            std::cin >> userNumber2;
            std::cout << std::endl;

            Calc(userNumber1, userNumber2, div);
            break;
        default:
            std::cout << "Неверный ввод, попробуйте ещё раз!\n" << std::endl;
            break;
        }
    } while (!(1 <= userChoice && userChoice <= 4));

    system("pause");
    return 0;
}