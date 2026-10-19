#include "Bank.h"
#include "Account.h"

#include <iostream>
#include <iomanip>

Bank::Bank()
{
	count = 0;
}

Bank::~Bank()
{

}

void Bank::CreateAccount()
{
	if (count >= 100)
	{
		std::cout << "계좌 개설 불가 ";
		return;
	}

	int Id;
	char InputName[50];
	int Balance;

	std::cout << "\n계좌 개설 ID: ";
	std::cin >> Id;

	std::cout << "\n계좌 개설 이름: ";
	std::cin >> std::setw(50) >> InputName;

	std::cout << "\n계좌 개설 입금액: ";
	std::cin >> Balance;

	accounts[count] = new Account(Id, InputName, Balance);
	count++;
}

void Bank::Inquire() const
{
	std::cout << "\n================================\n";
	// 예외 처리
	if (count == 0)
	{
		std::cout << "등록된 계좌가 없습니다.\n";
		std::cout << "================================\n";
		return;
	}

	for (int ix = 0; ix < count; ++ix)
	{
		//std::cout << "================================\n";
		accounts[ix]->ShowInfo();
		std::cout << "================================\n";
	}
}