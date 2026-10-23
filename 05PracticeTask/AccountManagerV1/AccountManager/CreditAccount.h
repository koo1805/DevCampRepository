#pragma once

#include "Account.h"

#include <fstream>

class CreditAccount : public Account
{
public:
	CreditAccount(int Id, const char* Name, int Balance);
	virtual void ShowInfo() override;
	virtual void Deposit(int Amount) override;

	virtual void Save(std::ostream& Out) const override;
};