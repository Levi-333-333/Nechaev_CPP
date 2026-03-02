#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#define DRAW std::cout << "Вы выбрали: " << userChoise << ". Противник выбрал: " << programmChoise << ". Итог: Ничья" << std::endl;
#define WIN std::cout << "Вы выбрали: " << userChoise << ". Противник выбрал: " << programmChoise << ". Итог: Вы победили" << std::endl;
#define LOSE std::cout << "Вы выбрали: " << userChoise << ". Противник выбрал: " << programmChoise << ". Итог: Вы проиграли" << std::endl;

void chichico()
{
	std::vector<std::string> choise
	{
		"Камень",
		"Ножницы",
		"Бумага"
	};

	std::srand(std::time(0));
	bool isCycleRun = true;

	while(isCycleRun)
	{
		std::cout << "Камень, Ножницы или Бумага? (1, 2 или 3)" << std::endl;
		int userInput;
		std::cin >> userInput;
		userInput--;

		if (userInput >= choise.size())	std::cout << "Давай нормально вводи есть же" << std::endl;
		else
		{
			std::string userChoise = choise[userInput];

			int programmInput = std::rand() % 3;
			std::string programmChoise = choise[programmInput];

			switch (userInput)
			{
			case 0:
				if (programmInput == 0)  DRAW
				if (programmInput == 1)  WIN
				if (programmInput == 2)  LOSE
				isCycleRun = false;
				break;
			case 1:
				if (programmInput == 0)  LOSE
				if (programmInput == 1)  DRAW
				if (programmInput == 2)  WIN
				isCycleRun = false;
				break;
			case 2:
				if (programmInput == 0)  WIN
				if (programmInput == 1)  LOSE
				if (programmInput == 2)  DRAW
				isCycleRun = false;
				break;
			default:
				std::cout << "Давай нормально вводи есть же" << std::endl;
			}
		}
	}
}