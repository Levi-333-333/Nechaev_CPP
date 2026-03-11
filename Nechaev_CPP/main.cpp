#include <iostream>
#include <fstream>
#include <Windows.h>
#include "queue.h"

/// Данная программа считывает данные о людях (имя и возраст) из файла и выводит на экран
/// сначала список лиц трудоспособного возраста, а затем - нетрудоспособного возраста,
/// сохраняя при этом исходный порядок расположения элементов хранимого в файле списка.
/// (Трудоспособным в программе считается возраст в диапазоне от 16 до 64 лет включительно).
/// <summary>
/// Функция для загрузки данных из файла и формирования очередей
/// </summary>
/// <param name="filename">Имя файла, содержащего сведения о людях (их имя и возраст)</param>
/// <param name="empl">Очередь из лиц трудоспособного возраста</param>
/// <param name="unempl">Очередь из лиц нетрудоспособного возраста</param>
void load_data(const char* filename, queue & empl, queue & unempl);
/// <summary>
/// Функция вывода данных из очереди
/// </summary>
/// <param name="q">Очередь, сведения из которой следуем отобразить на экране</param>
void show_data(queue & q);

void main()
{
		setlocale(LC_ALL, "Rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		// Создаем две очереди для работы с двумя категориями лиц:
		queue employable;
		queue unemployable;
		// Загружаем данные в очереди
		load_data("data.txt", employable, unemployable);
		//Выводим список лиц трудоспособного возраста:
		std::cout << "Лица из первой очереди:\n";
		show_data(employable);
		//Выводим список лиц нетрудоспособного возраста:
		std::cout << "Лица из второй очереди:\n";
		show_data(unemployable);
		system("pause");
}

void load_data(const char* filename, queue & empl, queue & unempl)
{
		std::ifstream f(filename);
		if (f.is_open())
		{
			int i = 0;
				//До конца файла
				while (!f.eof())
				{
						char* man = new char[61];
						//Считываем очередную строку
						f.getline(man, 61);
						char* name = new char[50];
						int age;
						//Получаем имя и возраст человека в отдельных переменных
						sscanf_s(man, "%49[^0-9] %d", name, 50, &age);
						if (i % 2 == 0) //Добавляем в список нетрудоспособных
							enqueue(unempl, name, age);
						else //Добавляем с писок трудоспособных
							enqueue(empl, name, age);

						i++;
				}
				f.close();
		}
}
void show_data(queue & q)
{
		int i = 0;
		while (q.size > 0)
		{
				man m;
				if (dequeue(q, m))
				{
						//Элемент получен, выводим данные
						std::cout << ++i << ".\t" << m.name << "\tВозраст:" << m.age << "\n";
				}
		}
}