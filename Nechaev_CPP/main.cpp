#include <string>
#include <Windows.h>
#include <iostream>

// Класс с чистыми виртуальными функциями (интерфейс). Определяет поведение, которое изменяется с помощью декоратора
class Component
{
public:
    virtual ~Component() {}
    virtual std::string DoSomething() = 0;
};

// Класс, реализующий поведение по умолчанию. У этого класса может быть несколько вариаций
class Player : public Component
{
public:
    std::string DoSomething() override
    {
        return "Игрок бьёт оружием";
    }
};

// Следует тому же интерфейсу, что и другие компоненты. Определяет обертку для всех конкретных декораторов
class Decorator : public Component
{
public:
    Decorator(Component* component)
    {
        this->component = component;
    }
    std::string DoSomething() override
    {
        return component->DoSomething();
    }
protected:
    Component* component;
};

// Конкретные декораторы вызывают обернутый объект и изменяют его результат.
// Декораторы могут вызывать родительскую реализацию операции, вместо того, чтобы вызвать обернутый объект напрямую
class CoolSword : public Decorator
{
public:
    CoolSword(Component* component) : Decorator(component) {}
    std::string DoSomething() override
    {
        // При наследовании обращение к родителю идет через оператор области видимости, поскольку поля с объектом класса в текущем классе нет.
        return "Используя крутой меч: " + Decorator::DoSomething();
    }
};

// Функция, работающая  со всеми объектами, использующая интерфейс компонента.Функция независима от конкретных классов компонентов с которыми работает
void PlayerTurn(Component* component)
{
    std::cout << "Ваше действие: " << component->DoSomething();
}

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Поддержка простых компонентов:
    Component* componentA = new Player;
    PlayerTurn(componentA);
    std::cout << std::endl << "==================" << std::endl;

    // Поддержка декоративных компонентов:
    Component* decoratorA = new CoolSword(componentA);
    PlayerTurn(decoratorA);
    std::cout << std::endl << "==================" << std::endl;

    delete componentA;
    delete decoratorA;

    system("pause");
}