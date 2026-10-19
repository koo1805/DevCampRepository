#pragma once
class Account
{
public:
	Account(int Id, const char* Name, int Balance);
	~Account();

public:
	void ShowInfo();

private:
	int Id = 0;
	char* Name = nullptr;
	int Balance = 0;
};