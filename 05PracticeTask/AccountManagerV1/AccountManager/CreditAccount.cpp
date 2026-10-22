#include "CreditAccount.h"

#include <iostream>

CreditAccount::CreditAccount(int Id, const char* Name, int Balance)
	: Account(Id, Name, Balance)
{

}

void CreditAccount::ShowInfo()
{
	Account::ShowInfo();

}

void CreditAccount::Deposit(int Amount)
{
	if (Balance <= 0)
	{
		std::cout << "다음 입금부터 이자율 1%가 적용됩니다.\n";
		Account::Deposit(Amount);
	}
	else
	{
		Amount += Amount / 100;
		Account::Deposit(Amount);
	}
}
