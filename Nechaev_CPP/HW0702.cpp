#include "HW0702.h"

string BankAccount::GetClientName()
{
	return clientName;
}

double BankAccount::GetBalance()
{
	return balance;
}

BankAccount::BankAccount(string clientName, double balance)
{
	this->clientName = clientName;
	this->balance = balance;
}

BankAccount* BankAccount::Deposit(double balance)
{
	this->balance += balance;
	return this;
}

BankAccount* BankAccount::Withdraw(double balance)
{
	this->balance -= balance;
	return this;
}

void BankAccount::PrintInfo()
{
	cout << "У пользователя " << GetClientName() << " " << GetBalance() << " деняг" << endl;
}

void BankAccount::CompairBalance(BankAccount other)
{
	if (balance > other.balance) cout << "У " << clientName << " больше денег, чем у " << other.clientName << " на " << balance - other.balance << " деняг." << endl;
	if (balance < other.balance) cout << "У " << clientName << " меньше денег, чем у " << other.clientName << " на " << other.balance - balance << " деняг." << endl;
	if (balance == other.balance) cout << "У " << clientName << " столько же денег, как и у " << other.clientName << endl;
}