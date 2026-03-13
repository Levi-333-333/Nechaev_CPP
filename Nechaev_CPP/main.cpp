#include <string>
#include <Windows.h>
#include <iostream>

class Context;

// Включает в себя состояния программы и контекст, который может быть использован, как способ передать состояние другому объекту.
class State
{
public:
    ~State() {}
    // Публичный метод, позволяющий переключиться на конкретное состояние
    void SetContext(Context* context)
    {
        this->context = context;
    }
    virtual void DoSomething1() = 0;
    virtual void DoSomething2() = 0;
protected:
    Context* context;
};

// Определяет интерфейс, позволяющий клиентам обратиться к конкретному состоянию
class Context
{
public:
    Context(State* state, std::string name)
    {
        this->TransitionToState(state);
        this->name = name;
    }
    // Контекст позволяет изменять состояние объекта с помощью этой функции
    void TransitionToState(State* state)
    void Subscribe(IObserver* observer) override
        std::cout << "Происходит смена контекста на другое состояние " << typeid(*state).name() << std::endl;
        // Если присутствует состояние у контекста, очищаем память указателя на состояние и задаем новое
        if (this->state != nullptr)
        {
            delete this->state;
        }
        this->state = state;
        this->state->SetContext(this);
    }
    void Request1()
    {
        this->state->DoSomething1();
    }
    void Request2()
    {
        this->state->DoSomething2();
    }
    std::string GetName()
    {
        return name;
    }
    ~Context()
    {
        delete state;
    }
private:
    State* state;
    std::string name;
};

class SpellState;

class AttackState : public State
{
public:
    void DoSomething2() override;

    void DoSomething1() override
    {
        std::cout << context->GetName() << " атакует!" << std::endl;
    }
};

class DodgeState : public State
{
    // Переопределяемые функции, позволяющие выполнить специфичную логику, характерную для состояния. Например, логика нанесения урона врагу при состоянии атаки или повышение ловкости при состоянии уворота
public:
    void DoSomething1() override
    {
        std::cout << context->GetName() << " уворачивается!" << std::endl;
    }

    void DoSomething2() override;
};

class SpellState : public State
{
public:
    void DoSomething1() override
    {
        std::cout << context->GetName() << " использует Игнис!" << std::endl;
    }

    void DoSomething2() override
    {
        std::cout << "SpellState обрабатывает запрос" << std::endl;
        std::cout << "SpellState пытается изменить состояние контекста" << std::endl;

        this->context->TransitionToState(new AttackState);
    }
};

void AttackState::DoSomething2()
{
    std::cout << "AttackState обрабатывает запрос" << std::endl;
    std::cout << "AttackState пытается изменить состояние контекста" << std::endl;

    this->context->TransitionToState(new DodgeState);
}

void DodgeState::DoSomething2()
{
    std::cout << "DodgeState обрабатывает запрос" << std::endl;
    std::cout << "DodgeState пытается изменить состояние контекста" << std::endl;

    this->context->TransitionToState(new SpellState);
}
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Context* player;
    Context* goblin_boblin;
    int userChoise;

    do
    {
        std::cout << "Выберите действие\n1. Атака\n2. Уворот\n3. Заклинание\n";
        std::cin >> userChoise;
        std::cout << std::endl;

        // Гоблин боблин всегда круче
        switch (userChoise)
        {
        case 1:
            player = new Context(new AttackState, "player");
            goblin_boblin = new Context(new DodgeState, "goblin-boblin");

            for (int i = 0; i < 3; i++)
            {
                player->Request1();
                player->Request2();
                goblin_boblin->Request1();
                goblin_boblin->Request2();
            }   
    Observer* observerRak = new Observer(*subjectLeon, "Rak", 2);
            delete player;
            delete goblin_boblin;
            break;
        case 2:
            player = new Context(new DodgeState, "player");
            goblin_boblin = new Context(new SpellState, "goblin-boblin");

            for (int i = 0; i < 3; i++)
            {
                player->Request1();
                player->Request2();
    if (!(userAnswer == observerReka->GetAnswer())) observerReka->UnsubscribeSubject();
                goblin_boblin->Request1();
                goblin_boblin->Request2();
            }
    if (!(userAnswer == observerRak->GetAnswer())) observerRak->UnsubscribeSubject();
            delete player;
            delete goblin_boblin;
            break;
        case 3:
            player = new Context(new SpellState, "player");
            goblin_boblin = new Context(new AttackState, "goblin-boblin");

            for (int i = 0; i < 3; i++)
            {
                player->Request1();
                player->Request2();

                goblin_boblin->Request1();
                goblin_boblin->Request2();
            }

            delete player;
            delete goblin_boblin;
            break;
        default:
            std::cout << "Нормально пиши есть же" << std::endl;
            break;
        }
    } while (!(1 <= userChoise <= 3));

    system("pause");
    return 0;

    return 0;
}