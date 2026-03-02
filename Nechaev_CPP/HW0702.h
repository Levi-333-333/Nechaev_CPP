#pragma once
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
public:
	BankAccount(string clientName, double balance);
	BankAccount* Deposit(double balance);
	BankAccount* Withdraw(double balance);
	void PrintInfo();
	string GetClientName();
	double GetBalance();
	void CompairBalance(BankAccount other);
private:
	string clientName;
	double balance;
};