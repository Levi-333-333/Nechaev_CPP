#pragma once
/// <summary>
/// Структура для хранения данных о некотором человеке
/// (для примера будем хранить имя и возраст)
/// </summary>
struct man
{
		/// <summary>
		/// Имя человека
		/// </summary>
		char name[50];
		/// <summary>
		/// Возраст человека
		/// </summary>
		int age;
};
/// <summary>
/// Структура для хранения элементов очереди
/// </summary>
struct elem
{
		/// <summary>
		/// Информационное поле
		/// </summary>
		man m;
		/// <summary>
		/// Адресное поле
		/// </summary>
		elem * next = nullptr;
};
/// <summary>
/// Структура для работы с очередью, хранящая указатели на ее начало и конец
/// </summary>
struct queue
{
		/// <summary>
		/// Первый элемент очереди (голова)
		/// </summary>
		elem * head = nullptr;
		/// <summary>
		/// Последний элемент очереди (хвост)
		/// </summary>
		elem * tail = nullptr;
		/// <summary>
		/// Количество элементов в очереди
		/// </summary>
		size_t size = 0;
};
/// <summary>
/// Функция добавления элемента в очередь
/// </summary>
/// <param name="queue">Структура, определяющая очередь, куда добавляется элемент</param>
/// <param name="name">Имя человека, добавляемое в очередь</param>
/// <param name="age">Возраст человека, добавляемый в тот же элемент очереди</param>
void enqueue(queue & queue, const char* name, int age);
/// <summary>
/// Извлечение элемента из очереди
/// </summary>
/// <param name="queue">Структура, определяющая очередь откуда извлекается значение</param>
/// <param name="man">Структура, содержащая сведения о человеке</param>
/// <returns>
/// true, в случае, если значение было успешно извлечено из очереди и
/// false, в противном случае.
/// </returns>
bool dequeue(queue & queue, man & man);
/// <summary>
/// Очистка очереди
/// </summary>
/// <param name="queue">Структура, определяющая очередь, которая будет удалена</param>
void clear(queue & queue);