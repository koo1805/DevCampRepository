#include <iostream>

class Base
{
public:
	Base()
	{
		std::cout << "Base() called\n";
	}
	~Base()
	{
		std::cout << "~Base() called\n";
	}

	void Play()
	{
	}
};

class Derived : public Base
{
public:
	Derived()
	{
		std::cout << "Derived() called\n";
	}
	~Derived()
	{
		std::cout << "~Derived() called\n";
	}
	
	void Attack()
	{
	}
};

int main()
{
	Base* b = new Derived();
	b->Play();
	//b->Attack();

	delete b;
	b = nullptr;
}
