#pragma once

#include "Account.h"

class CreditAccount : public Account
{
public:
	CreditAccount(int Id, const char* Name, int Balance);
	virtual void ShowInfo() override;
	virtual void Deposit(int Amount) override;
};