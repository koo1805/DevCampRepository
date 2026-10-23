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

	bool Save(const char* path) const;
	bool Load(const char* path);

	void Run();

	void TestAccount();

	inline void SetCount(int NewCount) { count = NewCount; }

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