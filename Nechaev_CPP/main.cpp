#include <string>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <Windows.h>

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::shared_ptr<std::string> stringPointer; // nullptr
	// Способ инициализации с помощью спец. функции make_shared<T>(), пердназначенной для этого
	std::shared_ptr<float> floatPointer = { std::make_shared<float>(36.6) };

	std::cout << stringPointer << std::endl; // 0000000
	std::cout << floatPointer << std::endl; // Ячейка памяти
	std::cout << *floatPointer << std::endl; // 36.6
	// У share_ptr есть функция, возвращающая кол-во объектов, на которые они ссылаются
	std::cout << floatPointer.use_count() << std::endl; // 1

	// Создание указателя на массив (доступно только с С++ 20)
	std::shared_ptr<int[]> intArrayPointer = { std::make_shared<int[]>(10) };
	for (int i = 0; i < 10; i++) intArrayPointer[i] = i * 2;
	for (int i = 0; i < 10; i++) std::cout << intArrayPointer[i] << ", "; // 0, 2, 4, 6, 8, 10, 12, 14, 16, 18
	std::cout << std::endl;

	system("pause");
	return 0;
}