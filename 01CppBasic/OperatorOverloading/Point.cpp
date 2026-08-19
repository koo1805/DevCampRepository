#include "Point.h"
#include <iostream>

Point::Point(int x, int y)
	: x(x), y(y)
{
	// 복잡한 작업 or 동적 할당 및 여러 줄의 초기화가 필요할 때.
}

Point Point::operator+(const Point& other) const
{
	return Point(x + other.x, y + other.y);
}

void Point::Print()
{
	std::cout << "(" << x << "," << y << ")\n";
}

Point operator-(const Point& left, const Point& right)
{
	return Point(left.x - right.x, left.y - right.y);
}
