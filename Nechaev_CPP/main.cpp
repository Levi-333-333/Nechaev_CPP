#include <Windows.h>
#include <iostream>

#define PAUSE system("pause"); system("cls")

struct Animal
{
    std::string type;
    std::string name;
    unsigned int age;

    Animal() = default;
    Animal(std::string _type, std::string _name, unsigned int _age)
    {
        type = _type;
        name = _name;
        age = _age;
    }
};

class Human
{
public:
	Human(unsigned int _age, unsigned int _fingers, double _lenght, double _weight, std::string _name, std::string _citizenship, bool _alive, Animal _pet, Animal _innerBeast);

    std::string GetName() { return name; }

    void PrintInfo();
    void Kill(Human& other);
    void HappyBirthday();
    void AwakenTheInnerBeast();
    std::string SaySomething(const std::string message);
private:
    unsigned int age;
    unsigned int fingers;
    double lenght;
    double weight;
    std::string name;
    std::string citizenship;
    bool majority;
    bool alive;
    Animal pet;
    Animal innerBeast;
};

Human::Human(unsigned int _age, unsigned int _fingers, double _lenght, double _weight, std::string _name, std::string _citizenship, bool _alive, Animal _pet, Animal _innerBeast)
{
    age = _age;
    fingers = _fingers;
    lenght = _lenght;
    weight = _weight;
    name = _name;
    citizenship = _citizenship;
    if (age >= 18) majority = true;
    else majority = false;
    alive = _alive;
    pet = _pet;
    innerBeast = _innerBeast;
}

void Human::PrintInfo()
{
    std::cout << name << ", " << age << "-и летний гражданин " << citizenship << " " << lenght << " м ростом и " << weight << " кг весом, по актуальным данным у которого " << fingers << " пальцев";
    if (alive) std::cout << std::endl;
    else std::cout << ", на данный момент является мёртвым." << std::endl;
}

void Human::Kill(Human& other)
{
    if (other.alive)
    {
        if (&name == &other.name)
        {
            std::cout << name << " убил себя!" << std::endl;
            alive = false;
        }
        else if (name == other.name)
        {
            std::cout << name << " убил дургого " << other.name << "!" << std::endl;
            other.alive = false;
        }
        else
        {
            std::cout << name << " убил " << other.name << "!" << std::endl;
            other.alive = false;
        }
    }
    else std::cout << "Нельзя убить мёртвого..." << std::endl;
}

void Human::HappyBirthday()
{
    age++;
    std::cout << "Сегодня " << name << " празднует свой день рождения!" << std::endl;
}

void Human::AwakenTheInnerBeast()
{
    std::cout << name << " пробуждает своего внутреннего зверя!" << std::endl;
    name = innerBeast.name;
    age = innerBeast.age;
    citizenship = innerBeast.type;
}

std::string Human::SaySomething(const std::string message)
{
    return name + " говорит: " + "\"" + message + "\"";
}

void main() 
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Human chelovek1{ 17, 10, 1.78, 71.4, "Leon", "РФ", true, {"Tigr", "Polosatik", 6}, {"Big Black Cock", "Petuh", 2} };
    Human chelovek2{ 43, 9, 1.82, 74.6, "Leon", "США", true, {"Dog", "Muhtar", 12}, {"Monkey", "Manki", 1} };
    Human chelovek3{ 17, 10, 1.76, 60.2, "Zloy David V Mute.", "Казакистан", true, {"Cat", "Murzik", 4}, {"Orel", "Kazahish Orel", 34} };

    std::cout << "Жили были на одной земле как-то 3 человека. двоих звали одинаково," << chelovek1.GetName() << ", и один " << chelovek3.GetName() << "." << std::endl;
    chelovek1.PrintInfo();
    chelovek2.PrintInfo();
    chelovek3.PrintInfo();
    PAUSE;

    std::cout << "Они были хорошими друзьями." << std::endl;
    PAUSE;

    std::cout << "Сегодня у одного из " << chelovek1.GetName() << " особенный день : " << std::endl;
    chelovek1.HappyBirthday();
    PAUSE;

    std::cout << "Но " << chelovek2.GetName() << " из США не пришёл на праздник к " << chelovek1.GetName() << " из РФ(хотя возможность была). \n" << chelovek1.SaySomething("Да что он о себе возомнил!? ") << std::endl;
    PAUSE;

    std::cout << chelovek1.GetName() << " начал готовить план мести..." << std::endl;
    PAUSE;

    chelovek2.HappyBirthday();
    std::cout << chelovek1.GetName() << " пришёл к нему заранее, под предлогом помощи. Они стоят на кухне и режут салаты.\n" << chelovek1.GetName() << " пошёл к раковине якобы помыть картошку, но когда он окозался за спиной у " << chelovek2.GetName() << ", " << chelovek1.GetName() << " Вонзает ему нож в спину!" << std::endl;
    chelovek1.Kill(chelovek2);
    PAUSE;

    std::cout << "Но вот незадача! Сразу после этого в дверь звонит " << chelovek3.GetName() << ".\n" << chelovek3.SaySomething("Я пришёл немного заранее. Я всё равно близко живу, мне дома делать нечего") << std::endl;
    PAUSE;

    std::cout << "Такой ранний приход " << chelovek3.GetName() << " не входил в планы " << chelovek1.GetName() << ". Нужно думать быстро..." << std::endl;
    PAUSE;

    std::cout << chelovek1.GetName() << " открыл дверь " << chelovek3.GetName() << " и провёл его сразу на кухню." << std::endl;
    std::cout << chelovek3.SaySomething("О нет, это что, труп " + chelovek2.GetName() + "?!?!?") << std::endl;
    std::cout << chelovek1.SaySomething("Да. И ты следующий.") << std::endl;
    chelovek1.Kill(chelovek3);
    PAUSE;

    std::cout << chelovek1.GetName() << " смотрит на 2 умерших тела своих товарищей, потом на окровавленный нож и начинает нервно и безудержно смеятся." << std::endl;
    std::cout << chelovek1.SaySomething("ААХАХХАХАХАХАХАХХАХАХАХАХАХАХАХАХАХАХАХХАХАХАХАХАХАХАХАХАХАХАХАХАХАХАХАХАХХАХАХАХАХАХАХХАХАХАХАХ") << std::endl;
    PAUSE;

    std::cout << "После 3-х минут безперерывного смеха... ";
    chelovek1.AwakenTheInnerBeast();
    PAUSE;

    chelovek1.PrintInfo();
    PAUSE;

    std::cout << "После пробуждения, " << chelovek1.GetName() << " прыгает на труп " << chelovek2.GetName() << " и начинает царапать его своими петушиными лапами." << std::endl;
    std::cout << "И царапал он так, пока не умер от изнемождения." << std::endl;
    chelovek1.Kill(chelovek1);
    PAUSE;

    std::cout << "Больше не жили были на одной земле как-то 3 человека. двоих звали одинаково," << chelovek1.GetName() << ", и один " << chelovek3.GetName() << "." << std::endl;
    chelovek1.PrintInfo();
    chelovek2.PrintInfo();
    chelovek3.PrintInfo();
    PAUSE;

    std::cout << "Конец. Если вас тронула эта история, пожалуйста, поставьте 5, я старался" << std::endl;

    system("pause");
}