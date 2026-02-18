#pragma once

#include <iostream>

template <typename Telement>
struct element
{
	Telement value;
	element* next = nullptr; // указатель на следующий элемент
};

// Добавление элемента в стек
// Вершина стека изменяется после добавления элемента. Это значит, что параметр stack должен передаваться по ссылке!
template <typename Telement>
void push(element<Telement>*& stack, int value);

// Удаление элемента из стека с возвращением хранимого значения
template <typename Telement>
bool pop(element<Telement>*& stack, int& value);

// Получение значения самого верхнего элемента в стеке
// Возвращается константный указатль на поле верхнего элемента в стеке
template <typename Telement>
const int* peek(const element<Telement>* stack);

// Получение следующего элемента стека
// Указатель на элемент стека может быть nullptr, если в списке больше нет элементов
template <typename Telement>
element<Telement>* NextElement(const element<Telement>* element);

// Получение последнего элемента стека
template <typename Telement>
element<Telement>* LastElement(const element<Telement>* element);

// Удаление всего стека
// Указатель на стек изменяется, поэтому параметр передается по ссылке
template <typename Telement>
void ClearStack(element<Telement>*& stack);

// Автоматическое заполнение всего стэка
template <typename Telement>
void FillStack(element<Telement>*& stack);

// Вывод всех значений в стеке
template <typename Telement>
void PrintStack(const element<Telement>* stack);