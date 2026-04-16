#include <iostream>
#include <Windows.h>
#include <vector>

class BankManager;
class BankAccount
{
public:
    friend BankManager;
    BankAccount(std::string name, int money)
    {
        this->name = name;
        this->money = money;
    }
private:
    std::string name;
    int money;
};
class BankManager
{
public:
    friend BankAccount;
    bool FPS(BankAccount* account1, BankAccount* account2, int amount) // Fast Payment System
    {
        if (account1->money < amount) return false;
        account1->money -= amount;
        account2 += amount;
        std::cout << "Перевод из аккаунта пользователя " << account1->name << " аккаунту пользователя " << account2->name << " прошло успешно!" << std::endl;
        return true;
    }
};

int main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BankManager admin = {};
    BankAccount* user1 = new BankAccount("Kirill", 53);
    BankAccount* user2 = new BankAccount("Flopa", 28);

    admin.FPS(user1, user2, 1);
    std::cout << "ахахаххахахаха 52 52 52 ахахахах" << std::endl;

	return 0;
}