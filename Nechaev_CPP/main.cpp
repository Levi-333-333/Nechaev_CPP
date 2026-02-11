#include <iostream>
#include <Windows.h>
using namespace std;

class Wallet
{
public:
	Wallet(unsigned int _money)
	{
		money = _money;
	}
	void pay(Wallet wallet)
	{
		cout << "оплата прошла успешно" << endl;
	}
private:
	unsigned int money;
};

void main()
{
	setlocale(LC_ALL, "Ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Wallet wallet1(12);
	Wallet wallet2(13);

	wallet1.pay(400); // Сработало
}