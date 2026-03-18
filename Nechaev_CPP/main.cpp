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

	unsigned int n { 5 };
	std::unique_ptr<int[]> pointerToArray{ std::make_unique<int[]>(n) };

	for (int i = 0; i < n; i++)
	{
		pointerToArray[i] = (i + 1) * 3;
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << pointerToArray[i] << ", ";
	}

	pointerToArray.reset();

	system("pause");
	return 0;
}
//      Практика
// 1. Необходимо создать уникальный указатель, который бы указывал на массив целочисленных беззнкаовых значений.
// 2. В цикле данный массив заполнить любым способом.
// 3. Вывести значения каждого из элементов в цикле.
// 4. В конце высвободить память для уникального указателя.