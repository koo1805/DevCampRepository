#pragma once
class Account
{
public:
	Account(int Id, const char* Name, int Balance);
	~Account();

public:
	// Getter
	inline int GetId() const { return Id; }
	inline int GetBalance() const { return Balance; }

public:
	void ShowInfo();
	void Deposit(int Amount);
	bool WithDraw(int Amount);

private:
	int Id = 0;
	char* Name = nullptr;
	int Balance = 0;
};