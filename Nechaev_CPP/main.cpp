#include <iostream>
#include <Windows.h>
#include <vector>

class Person
{
public:
    virtual ~Person() {}
    virtual void CheckPassport() = 0;
};
class MigrantFromBangladesh : public Person
{
public:
    void CheckPassport() override
    {
        std::cout << "Пасспортные данные не верны." << std::endl;
    }
    void Run()
    {
        std::cout << "Тупой мигрант пытается убежать! Растрел!!" << std::endl;
    }
};
class Moscouich : public Person
{
    void CheckPassport() override
    {
        std::cout << "Пасспортные данные верны." << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<std::unique_ptr<Person>> airport { std::make_unique<MigrantFromBangladesh>(), std::make_unique<Moscouich>() };
    
    for (int i = 0; i < airport.size(); ++i)
    {

        airport[i]->CheckPassport();
        if (MigrantFromBangladesh* temp = dynamic_cast<MigrantFromBangladesh*>(airport[i].get())) temp->Run();
    }

    for (int i = 0; i < airport.size(); ++i)
    {
        airport[i].reset();
    }

	return 0;
}