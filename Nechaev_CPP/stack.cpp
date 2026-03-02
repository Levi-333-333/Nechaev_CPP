#include "stack.h"

template <typename Telement>
void push(element<Telement>*& stack, Telement value)
{
	element<Telement>* newElement = new element<Telement>;
	newElement->value = value;

	// Если стек при добавлении пуст, задаем новый элемент, как первый
	if (!stack) stack = newElement;
	else
	{
		// Стек уже существует, новый элемент размещается на вершине
		newElement->next = stack;
		stack = newElement;
	}
}

template <typename Telement>
bool pop(element<Telement>*& stack, Telement& value)
{
	// Извлечение элемента из стека, если он не пуст
	if (!stack) return false;
	// Необходимо сохранять ссылку на самый верхний элемент
	element<Telement>* ref = stack;
	value = stack->value;
	stack = stack->next; // смещение указателя на новую вершину
	delete ref;
	return true;
}

template <typename Telement>
const int* peek(const element<Telement>* stack)
{
	// Получение значения с вершины стека, если он не пуст
	if (!stack) return nullptr;
	return &stack->value;
}

// Возвращение следующего элемента в стеке от передаваемого в параметр
template <typename Telement>
element<Telement>* NextElement(const element<Telement>* element)
{
	if (element) return element->next;
	return nullptr;
}

// Возвращение последнего элемента в стеке
template <typename Telement>
element<Telement>* LastElement(const element<Telement>* elem)
{
	// Перебор указателей на последующий элемент в стеке
	if (elem) while (elem->next) elem = elem->next;
	return (element<Telement>*)elem;
}

// Очистка памяти всех элементов стека посредством обращения к ним через указатель
template <typename Telement>
void ClearStack(element<Telement>*& stack)
{
	while (stack)
	{
		element<Telement>* toRemove = stack; // создание указателя на объект, который нужно очистить
		stack = stack->next; // продвижение по следующему элементу в стеке
	}
	// 1 цикл: 
	//			- создаем объект элемента в который записываем первый элемент стека
	//			- в параметр записываем следующий элемент стека, как бы продвигая итерацию вперед
}

template <typename Telement>
void FillStack(element<Telement>*& stack)
{
	for (int i = 0; i <= 20; i++)
	{
		push(stack, i);
	}
}

template <typename Telement>
void PrintStack(const element<Telement>* stack)
{
	// Ключевое слово авто настоятельно рекомендуется к использованию только в циклах и линейных списках! Компилятору гораздо удобнее самостоятельно определять тип данных, если он предсказуем, например в массивах или в линейных списках
	auto currentElement = (element<Telement>*)stack; //  Получение указателя на вершину стека
	auto lastElement = LastElement(stack);
	while (currentElement)
	{
		// Получение значения текущего элемента стека
		auto value = peek(currentElement);

		std::cout << *value << std::endl;

		// Выставление следующего элемента в стеке как текущего
		currentElement = NextElement(currentElement);
	}
}