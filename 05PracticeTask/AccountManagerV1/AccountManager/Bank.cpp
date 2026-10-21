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

	//std::cout << accounts[count]->GetBalance();

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

void Bank::Deposit()
{
	int Id;
	int InMoney;
	int TempMoney;

	Account* TargetAccount;

	while (true)
	{
		std::cout << "\n입금할 계좌를 입력하세요: ";
		std::cin >> Id;
		
		TargetAccount = FindAccount(Id);

		if (nullptr != TargetAccount)
		{
			std::cout << "\n입금할 금액을 입력해 주세요: ";
			std::cin >> InMoney;
			TempMoney = TargetAccount->GetBalance();

			TargetAccount->Deposit(InMoney);

			std::cout << "\n------------------------------\n";
			std::cout << "현재 계좌: " << Id << " | 변경된 금액: " << TempMoney << " -> " << TargetAccount->GetBalance() << "\n";

			break;
		}
	}
	
}

void Bank::WithDraw()
{
	int Id;
	int InMoney;
	int TempMoney;

	Account* TargetAccount;

	while (true)
	{
		std::cout << "\n출금할 계좌를 입력하세요: ";
		std::cin >> Id;

		TargetAccount = FindAccount(Id);

		if (nullptr != TargetAccount)
		{
			std::cout << "\n출금할 금액을 입력해 주세요: ";
			std::cin >> InMoney;
			TempMoney = TargetAccount->GetBalance();

			if (TargetAccount->WithDraw(InMoney))
			{
				std::cout << "\n------------------------------\n";
				std::cout << "현재 계좌: " << Id << " | 변경된 금액: " << TempMoney << " -> " << TargetAccount->GetBalance() << "\n";

				break;
			}
		}
	}
}

Account* Bank::FindAccount(int TargetId) const
{
	for (int ix = 0; ix < count; ++ix)
	{
		int FindId = accounts[ix]->GetId();

		if (FindId == TargetId)
		{
			std::cout << "순회 횟수: " << ix << "\n";
			return accounts[ix];
		}
	}

	std::cout << "입력된 계좌는 없는 계좌 입니다.\n";

	return nullptr;
}

void Bank::Run()
{
	while (true)
	{
		if (!IsActiveTitle)
		{
			std::cout << "###############################################\n";
			std::cout << "#                     BANK                    #\n";
			std::cout << "###############################################\n";
			IsActiveTitle = true;
		}
		
		char SelectNum = {};

		std::cout << "\n=== Menu ===\n\n";
		std::cout << "1. 계좌 생성\n"
			<< "2. 전체 계좌 조회\n"
			<< "3. 계좌 입금\n"
			<< "4. 계좌 출금\n"
			<< "\n 나가기는 Q를 입력해 주세요!\n";

		std::cin >> SelectNum;

		if (SelectNum == 'q' || SelectNum == 'Q')
		{
			return;
		}

		switch (SelectNum)
		{
		case '1':
			CreateAccount();
			break;

		case '2':
			Inquire();
			break;

		case '3':
			Deposit();
			break;
		
		case '4':
			WithDraw();
			break;

		default:
			break;
		}
	}
}