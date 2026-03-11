#include <iostream>
#include <vector>

class Character
{
public:
    Character(int health, int strenght)
    {
        this->health = health;
        this->strenght = strenght;
    }

    void PrintInfo()
    {
        std::cout << "Ваше здоровье: " << health << " Ваша сила: " << strenght << std::endl;
    }

    int GetHealth() { return health; }
    void SetHealth(int health) { this->health = health; }

    int GetStrenght() { return strenght; }
    void SetStrenght(int strenght) { this->strenght = strenght; }
private:
    int health;
    int strenght;
};

int main()
{
    setlocale(LC_ALL, "Ru");

    Character* character = new Character(15, 3);

    auto poisionPoition = [](Character* character) {character->SetHealth(character->GetHealth() - 4); };
    auto healthPoition = [](Character* character) {character->SetHealth(character->GetHealth() + 4); };
    auto cursedSword = [](Character* character) {character->SetHealth(character->GetHealth() - 2); character->SetStrenght(character->GetStrenght() + 2); };

    character->PrintInfo();
    std::cout << std::endl;

    std::cout << "Магазин какащек:\n1. Зелье здоровья\n2. Зелье отравления\n3. Точно не проклятый меч\nВведите порядковый номер предмета: ";
    int userInput;
    std::cin >> userInput;
    std::cout << std::endl;

    switch (userInput)
    {
    case 1:
        poisionPoition(character);
        character->PrintInfo();
        break;
    case 2:
        healthPoition(character);
        character->PrintInfo();
        break;
    case 3:
        cursedSword(character);
        character->PrintInfo();
        break;
    default:
        std::cout << "Ну ты нормально вводить будешь нет?" << std::endl;
        break;
    }
}