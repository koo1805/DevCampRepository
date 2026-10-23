#pragma once

#include <fstream>

class Account
{
public:
	Account(int Id, const char* Name, int Balance);
	Account(const Account& other);
	virtual ~Account();

public:
	// Getter
	inline int GetId() const { return Id; }
	inline int GetBalance() const { return Balance; }
	inline char* GetName() const { return Name; }

public:
	virtual void ShowInfo();
	virtual void Deposit(int Amount);
	bool WithDraw(int Amount);

	void SetName(const char* NewName);

	virtual void Save(std::ostream& Out) const;

protected:
	void WriteRecord(std::ostream& Out, int Type, int Donation) const;

protected:
	int Id = 0;
	char* Name = nullptr;
	int Balance = 0;
};