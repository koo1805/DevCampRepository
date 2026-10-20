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
	void Deposit();
	void WithDraw();

	Account* FindAccount(int TargetId) const;

	void Run();

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