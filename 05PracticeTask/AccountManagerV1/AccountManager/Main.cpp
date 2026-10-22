#include <iostream>
#include "Account.h"
#include "CreditAccount.h"
#include "DonationAccount.h"
#include "Bank.h"

int main()
{
	//Account account(1001, "Kim", 100000);
	//account.ShowInfo();

	Bank bank;
	bank.Run();

	/* Test Code 03 =================================================================================
	CreditAccount credit(1001, "Kim", 0);
	Account* cAccount = &credit;
	cAccount->Deposit(10000);
	cAccount->ShowInfo();

	DonationAccount donation(1002, "asd", 0);
	Account* dAccount = &donation;
	dAccount->Deposit(10000);
	dAccount->ShowInfo();
	dAccount->Deposit(10000);
	dAccount->ShowInfo();		//*/

	/* Test Code 02 =================================================================================
	Account original(1001, "Kim", 10000);
	Account copy(original);
	original.ShowInfo();
	copy.ShowInfo();

	std::cout << "====================\n";
	std::cout << (&original != &copy) << '\n';
	std::cout << (original.GetName() != copy.GetName()) << '\n';
	std::cout << (std::strcmp(original.GetName(), copy.GetName()) == 0) << '\n';
	std::cout << "====================\n";

	original.Deposit(3000);
	original.SetName("Lee");
	original.ShowInfo();
	std::cout << "- - - - - - - -\n";
	copy.ShowInfo();

	std::cout << "====================\n";
	std::cout << "Original: " << &original << "\n";
	std::cout << "C o p y : " << &copy << "\n";				//*/

	/* Test Code 01 =================================================================================
	int TargetId;
	std::cout << "test: ";
	std::cin >> TargetId;
	std::cout << bank.FindAccount(TargetId); //*/

	return 0;
}