#include "queue.h"
#include <cstring>
/// <summary>
/// Вспомогательная функция для формирования элемента очереди.
/// Поскольку, ее вызов сторонними функциями не предусматривается,
/// ее описание отсутствует в заголовочном файле.
/// </summary>
/// <param name="name">Имя человека, сохраняемого в структуре</param>
/// <param name="age">Возраст человека, сохраняемый в структуре</param>
/// <returns>Структура, содержащие сведения о человеке</returns>
inline man create_elem(const char* name, int age)
{
		man m;
		// Если бы в структуре была строка в виде динамического массива, здесь нужно было бы
		// предварительно выделить память под эту строку!
		strcpy_s(m.name, name);
		m.age = age;
		return m;
}
void enqueue(queue & queue, const char* name, int age)
{
		// Создаем новый элемент для размещения в очереди
		man newm = create_elem(name, age);
		elem * newel = new elem;
		newel->m = newm;
		if (!queue.tail)
		{
				// Если очереди еще не было, новый элемент становится единственным в ней
				queue.head = queue.tail = newel;
		}
		else
		{
				// Если очередь уже была, новый элемент помещается в конец:
				queue.tail->next = newel;
				queue.tail = newel;
		}
		queue.size++;
}
bool dequeue(queue & queue, man & m)
{
		if (!queue.head) // Очереди нет
			return false; // Вернуть значение невозможно
		// Сохраняем возвращаемое значение
		m = queue.head->m;
		// Сохраняем указатель на начало очереди
		elem * rem = queue.head;
		// Изменяем адрес головного элемента
		queue.head = queue.head->next;
		// Если бы в структуре была строка в виде динамического массива, здесь нужно было бы
		// предварительно очистить память из-под этой строки!
		// Удаляем элемент с головы очереди
		delete rem;
		// Если элементов в очереди не осталось, обнуляем и указатель на ее конец.
		if (!queue.head) queue.tail = nullptr;
		queue.size--;
		return true;
}
void clear(queue & queue)
{
		// Проходим по всем элементам очереди, пока она не опустеет
		while (queue.head)
		{
				elem * rem = queue.head; // Сохраняем ссылку на удаляемый элемент
				queue.head = queue.head->next;// Переносим "голову" очереди вперед
				delete rem; // Удаляем элемент по сохраненному указателю
		}
		queue.size = 0; // Обнуляем размер очереди
		queue.tail = nullptr; // Обновляем указатель на последний элемент
}