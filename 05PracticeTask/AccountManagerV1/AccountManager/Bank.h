#pragma once

class Account;

class Bank
{
public:
	Bank();
	~Bank();

public:
	void SelectAccount();
	void CreateAccount();
	void CreateCreditAccount();
	void CreateDonationAccount();
	void Inquire() const;
	void Deposit();
	void WithDraw();

	Account* FindAccount(int TargetId) const;

	void Run();

	void TestAccount();

private:
	Account* accounts[100] = {};

	int count;

	bool IsActiveTitle = false;

	/* 깔끔한 코드
	static const int capacity = 100;
	uint32_t count = 0;
	Account* accounts[capacity] = {};
	//*/
};