#include "Account.h"
#include <iostream>
#include <cstring>

Account::Account(int Id, const char* Name, int Balance)
	: Id(Id), Balance(Balance)
{
	size_t NameLength01 = strlen(Name) + 1;

	this->Name = new char[NameLength01];

	strcpy_s(this->Name, NameLength01, Name);
}

Account::Account(const Account& other)
	: Id(other.Id), Balance(other.Balance)
{
	size_t NameLength01 = strlen(other.Name) + 1;

	Name = new char[NameLength01];

	strcpy_s(Name, NameLength01, other.Name);
}

Account::~Account()
{
	if (Name != nullptr)
	{
		delete[] Name;
		Name = nullptr;
	}

}

void Account::ShowInfo()
{
	std::cout << "계좌번호: " << Id << '\n';
	std::cout << "이름: " << Name << '\n';
	std::cout << "잔액: " << Balance << '\n';
}

void Account::Deposit(int Amount)
{
	Balance += Amount;
}

bool Account::WithDraw(int Amount)
{
	if (Balance < Amount)
	{
		std::cout << "잔액이 부족합니다. 남은 잔액: " << Balance << "\n";
		return false;
	}
	else
	{
		Balance -= Amount;
		return true;
	}
}

void Account::SetName(const char* NewName)
{
	size_t NameLength01 = strlen(NewName) + 1;

	delete[] Name;
	Name = nullptr;

	Name = new char[NameLength01];

	strcpy_s(Name, NameLength01, NewName);
}