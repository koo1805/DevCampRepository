#pragma once

#include <iostream>

class Point
{
public:
	Point(int x = 0, int y = 0);

	// 덧셈 연산자 오버로딩 - 멤버 함수 형태로 구현.
	Point operator+(const Point& other) const;

	// friend로 연산자 오버로딩.
	friend Point operator-(const Point& left, const Point& right);

	// friend로 함수 등록.
	friend std::ostream& operator<<(
		std::ostream& os,
		const Point& point
	);

	// 값 출력 함수.
	void Print();

private:
	int x = 0;
	int y = 0;
};