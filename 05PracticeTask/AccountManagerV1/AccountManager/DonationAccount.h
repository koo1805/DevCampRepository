#pragma once

#include "Account.h"

class DonationAccount : public Account
{
public:
	DonationAccount(int Id, const char* Name, int Balance);
	virtual void ShowInfo() override;
	virtual void Deposit(int Amount) override;

protected:
	int DonationTotal = 0;
};