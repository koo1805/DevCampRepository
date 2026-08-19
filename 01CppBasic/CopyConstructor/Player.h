#pragma once

class Player
{
public:
	Player();
	Player(const char* inName);
	~Player();

//private:
	// 삭제.
	// 복사 생성자.
	Player(const Player& other);

	// 대입(=) 연산자 오버로딩.
	// 연산자->연산자를 이름으로 갖는 함수.
	Player& operator=(const Player& other);

public:
	// Getter (값을 반환하는 함수).
	inline const char* GetName() const { return name; }

private:
	// 동적 할당을 사용하는 문자열.
	char* name = nullptr;
};