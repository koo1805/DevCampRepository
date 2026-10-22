#include "DonationAccount.h"

#include <iostream>

DonationAccount::DonationAccount(int Id, const char* Name, int Balance)
	: Account(Id, Name, Balance)
{

}

void DonationAccount::ShowInfo()
{
	Account::ShowInfo();

	std::cout << "기부금 총액: " << DonationTotal << "\n";
}

void DonationAccount::Deposit(int Amount)
{
	if (Balance <= 0)
	{
		std::cout << "다음 입금부터 입금액의 1%가 기부금으로 적용됩니다.\n";
		Account::Deposit(Amount);
	}
	else
	{
		DonationTotal += Amount / 100;
		Amount -= Amount / 100;
		Account::Deposit(Amount);
	}
}
