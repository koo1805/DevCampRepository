#pragma once

#include "Account.h"

#include <fstream>

class DonationAccount : public Account
{
public:
	DonationAccount(int Id, const char* Name, int Balance, int DontaionTotal = 0);
	virtual void ShowInfo() override;
	virtual void Deposit(int Amount) override;

	virtual void Save(std::ostream& Out) const override;

protected:
	int DonationTotal = 0;
};