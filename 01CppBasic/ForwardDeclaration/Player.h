#pragma once

//#include "Weapon.h"

// 전방 선언.
// 1. 컴파일 시간 단축.
// 2. 헤더 순환 참조 방지.
class Weapon;

// Ctrl + K + O.
class Player
{
public:
	Player();
	~Player();

private:
	// Weapon 변수.
	Weapon* weapon;
};