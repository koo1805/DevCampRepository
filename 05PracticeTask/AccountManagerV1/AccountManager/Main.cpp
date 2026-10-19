#include <iostream>
#include "Account.h"
#include "Bank.h"

int main()
{
	//Account account(1001, "Kim", 100000);
	//account.ShowInfo();

	Bank bank;
	bank.Inquire();
	bank.CreateAccount();
	bank.CreateAccount();
	bank.Inquire();
}