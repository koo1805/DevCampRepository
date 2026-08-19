#include "Player.h"
#include <iostream>

Player::Player()
{
	std::cout << "Player() called\n";
}

Player::Player(const char* inName)
{
	// 문자열 복사.
	size_t length = strlen(inName) + 1;
	name = new char[length]{};
	strcpy_s(name, length, inName);

	std::cout << "Player(const char* inName) called\n";
}

// 복사 생성자.
Player::Player(const Player& other)
	//: name(other.name)
{
	// 얕은 복사 ? -> 포인터 주소 값만 복사.
	//name = other.name;

	// 깊은 복사(Deep Copy).
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);

	std::cout << "Player(const Player& other) called\n";
}

Player::~Player()
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}
}

Player& Player::operator=(const Player& other)
{
	// 복사 처리.
	size_t length = strlen(other.name) + 1;
	name = new char[length] {};
	strcpy_s(name, length, other.name);

	std::cout << "operator=(const Player& other) called\n";

	return *this;
}
