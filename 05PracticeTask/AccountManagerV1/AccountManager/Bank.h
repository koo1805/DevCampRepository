#pragma once

class Account;

class Bank
{
public:
	Bank();
	~Bank();

public:
	void CreateAccount();
	void Inquire() const;

private:
	Account* accounts[100];

	int count;
};