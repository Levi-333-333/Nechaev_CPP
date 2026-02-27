#include <iostream>
#include <Windows.h>
#include <string>

/// <summary>
/// Класс, ответственный за реализацию паттерна "шаблон". Позволяет отдать приказ работникам, которые создаются при наследовании этого родительского класса.
/// </summary>
class FlowerBoss
{
public:
	// Шаблонный метод
	void GiveOrder() const
	{
		this->WateringFlowers();
		this->CollectFlowers();
		this->PackFlowers();
		this->SellFlowers();
	}

	void RequireOrder() const
	{
		this->RequireWateringFlowers();
		this->RequireCollectFlowers();
		this->RequirePackFlowers();
		this->RequireSellFlowers();
	}
protected:
	void CollectFlowers() const
	{
		std::cout << "Цветочный босс говорит собрать цветы" << std::endl;
	}
	void SellFlowers() const
	{
		std::cout << "Цветочный босс говорит продать цветы" << std::endl;
	}
	void WateringFlowers() const
	{
		std::cout << "Цветочный босс говорит полить цветы" << std::endl;
	}
	void PackFlowers() const
	{
		std::cout << "Цветочный босс говорит упаковать цветы" << std::endl;
	}

	virtual void RequireWateringFlowers() const {};
	virtual void RequireCollectFlowers() const {};
	virtual void RequirePackFlowers() const {};
	virtual void RequireSellFlowers() const {};

};

class PlatonFlower : public FlowerBoss
{
	void RequireCollectFlowers() const override
	{
		std::cout << "Платон слушает и повинуется собирать цветы" << std::endl;
	}
	void RequirePackFlowers() const override
	{
		std::cout << "Платон слушает и повинуется упаковать цветы" << std::endl;
	}
};

class AnotherPlatonFlower : public FlowerBoss
{
	void RequireWateringFlowers() const override
	{
		std::cout << "Другой Платон слушает и повинуется полить цветы" << std::endl;
	}
	void RequirePackFlowers() const override
	{
		std::cout << "Другой Платон слушает и повинуется упаковать цветы" << std::endl;
	}
};

/// <summary>
/// Функция, которая взаимодействует с паттерном "шаблон", исполняя его одну из главных функций
/// </summary>
/// <param name="flowerBoss">Указатель на наследуемый объект шаблона с имплеминтацией</param>
static void MennageWorker(FlowerBoss* flowerBoss)
{
	flowerBoss->GiveOrder();
}
/// <summary>
/// Функция, которая взаимодействует с паттерном "шаблон", исполняя его одну из главных функций
/// </summary>
/// <param name="worker">Указатель на наследуемый объект шаблона с имплеминтацией</param>
static void WorkersWork(FlowerBoss* worker)
{
	worker->RequireOrder();
}

int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	PlatonFlower* worker1 = new PlatonFlower;
	AnotherPlatonFlower* worker2 = new AnotherPlatonFlower;
	MennageWorker(worker1);
	WorkersWork(worker1);
	WorkersWork(worker2);

	delete worker1;
	delete worker2;

	system("pause");
	return 0;
}