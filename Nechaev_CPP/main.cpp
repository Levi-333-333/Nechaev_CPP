#include <iostream>
#include <Windows.h>
#include <string>

// Ф-я, принимающая в качестве третьего параметра указатель на функцию, которая выступает в виде лямбда-выражения
void DoSomething(int number1, int number2, int (*operation)(int, int))
{
	std::cout << operation(number1, number2) << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Безымянная лямбда
	[]() {std::cout << "Привет РПО" << std::endl; } ();

	// Именованная лямбда
	auto hello{ []() {std::cout << "Привет РПО" << std::endl; } };

	// Лямбда с параметрами
	auto printInfo{ [](const std::string& info) {std::cout << info << std::endl; } };

	// Лямбда, которая возвращает значение
	auto sum{ [](int a, int b) {return a + b; } };

	// Лямбда с явным возвращаемым занчением
	std::cout << [](int x, int y) -> double {return x + y; } (5, 5) << std::endl;

	// Лямбда для функции
	auto sub{ [](int number1, int number2) {return number1 - number2; } };

	hello();
	printInfo("Привет РПО");
	std::cout << sum(3, 4) << std::endl;
	DoSomething(10, 5, sub);

	system("pause");
	return 0;
}