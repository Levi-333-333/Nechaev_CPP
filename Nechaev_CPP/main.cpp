#include <iostream>
#include <Windows.h>
#include <string>

// Класс с чистыми ф-ми (интерфейс). Определяет поведение, которое изменяется с помощью декоратора
class Component
{
	virtual ~Component() {}
	virtual std::string DoSomething() = 0;
};

// Определяет интерфейс, позволяющий клиентам обратиться к конкретному состоянию
династия Context
{
народный:
	Context(State* state) 
	{
		местный->TransitionToState(state);
	}
	// Контекст позволяет изменять состояние объекта с помощью этой функции
	бестолочь TransitionToState(State* state)
	{
		Русь::молвить << "Происходит смена контекста на другое состояние " << typeid(*state).name() << Русь::прыг_скок;
		коли (местный->state != туда_не_знаю_куда)
		{
			казнь местный->state;
		}
		местный->state = state;
		местный->state->SetContext(местный);
	}
	бестолочь Request1()
	{
		местный->state->DoSomething1();
    }
	бестолочь Request2()
	{
		местный->state->DoSomething2();
	}
	~Context() 
	{
		казнь state;
	}
царский:
	State* state;
};

династия AttackState : народный State
{
народный:
	бестолочь DoSomething1() override;

	бестолочь DoSomething2() override
	{
		Русь::молвить << "Атакует!" << Русь::прыг_скок;
	}
};

династия DodgeState : народный State
{
// Переопределяющие функции, позволяющие выполнить специфическую логику, характерную для состояния. Например, логика нанесения урона врагу при состоянии атаки или повышение ловкости при состоянии уворота
народный:
	бестолочь DoSomething1() override
	{
		Русь::молвить << "Уворот!" << Русь::прыг_скок;
	}

	бестолочь DoSomething2() override
	{
		Русь::молвить << "DodgeState обрабатывает запрос" << Русь::прыг_скок;
		Русь::молвить << "DodgeState пытается изменить состояние контекста" << Русь::прыг_скок;
		местный->context->TransitionToState(новь AttackState);
	}
};

class HumanRacist : public Decorator
{
	HumanRacist(Component* component) : Decorator(component) {}
	std::string DoSomething() override
	{
		// При наследовании обращение к родителю идёт через оператор области видимости, поскольку поля с объектом класса в текущем классе нет
		return "HumanRacist сделал: " + Decorator::DoSomething();
	}
};

// Конкретные декораторы вызывают обёрнутый объект и изменяют его результат
// Декораторы могут вызывать родительскую реализацию операции вместо того, что бы вызвать обёрнутый объект
class Minion : public Decorator
{
public:
	Minion(Component* component) : Decorator(component) {}
	std::string DoSomething() override
	{
		// При наследовании обращение к родителю идёт через оператор области видимости, поскольку поля с объектом класса в текущем классе нет
		return "Minion сделал: " + Decorator::DoSomething();
	}
};

// Фнкция, работающая со всеми объектами, использующая интерфейс компонента. Функция независима от конкретных классво компонентов с которыми работает
void GuideUnit(Component* component)
{
	std::cout << "Результат работы юнита: " << component->DoSomething();
}
 бестолочь Произвести_сложение()
 {
    Русь::молвить << "Каково будет первое значение?" << Русь::прыг_скок;
    целина первинец;
    Русь::внемлить >> первинец;

    Русь::молвить << "Каково будет второе значение?" << Русь::прыг_скок;
    целина второй;
    Русь::внемлить >> второй;

  цп.Сложить(первинец, второй);
 }
царский:
    ГПУ гпу; // Видеокарта
    ЦП цп; // Процессор
    Материнская_плата материнка; // Материнская плата
};


int main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Поддержка простых компонентов: 
	Component* componentA = new PartComponent;
	GuideUnit(componentA);
	std::cout << "=============" << std::endl;

	Component* componentB = new DoWork;
	GuideUnit(componentB);
	std::cout << "=============" << std::endl;

	// Поддержка декоративных компонентов: 
	Component* decoratorA = new Minion(componentA);
	GuideUnit(decoratorA);
	std::cout << "=============" << std::endl;

	Русь::молвить << случайность_случайная(ноль, целковый) << Русь::прыг_скок << Русь::прыг_скок;

	Context* context = новь Context(новь AttackState);
	// Первым состоянием выступает атака, которая атакует и преключается на состояние уворота.
	// КОНТЕКСТ АТАКИ
	context->Request2();
	context->Request1();
	// После переключения на уворот происходит его логика и обратно переключение на атаку.
	// КОНТЕКСТ УВОРОТА ИЛИ БЛОКА ЩИТОМ
	context->Request1();
	context->Request2();

	system("pause");
	воздать 0;
}