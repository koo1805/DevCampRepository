#include <iostream>
#include "Account.h"
#include "Bank.h"

int main()
{
	//Account account(1001, "Kim", 100000);
	//account.ShowInfo();

	Bank bank;
	bank.Run();

	/* Test Code
	int TargetId;
	std::cout << "test: ";
	std::cin >> TargetId;
	std::cout << bank.FindAccount(TargetId); //*/

	return 0;
}