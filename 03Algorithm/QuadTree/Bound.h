#pragma once

#include <iostream>

// 사각 영역을 표현하는 클래스
class Bound
{
public:
	Bound(int x, int y, int width = 1, int height = 1)
		: x(x), y(y), width(width), height(height)
	{ }

public:
	// Getter
	int GetX() const { return x; }
	int GetY() const { return y; }
	int Getwidth() const{ return width; }
	int Getheight() const { return height; }

	// 오른쪽 및 아래쪽 경계 Getter
	int GetXMax() const { return x + width; }
	int GetYMax() const { return y + height; }

	// Setter

	// 점이 영역 안에 포함되는지 확인하는 함수
	bool Contains(int pointX, int pointY) const
	{
		return pointX >= x && pointX < GetXMax()
			&& pointY >= y && pointY < GetYMax();
	}

	// 다른 사각형이 현재 영역에 포함 되는지 확인
	bool Contains(const Bound& other) const
	{
		return other.x >= x && other.GetXMax() < GetXMax()
			&& other.y >= y && other.GetYMax() < GetYMax();
	}

	// 다른 사각형과 겹치는지 확인하는 함수
	bool Interects(const Bound& other) const
	{
		return other.x < GetXMax() && other.GetXMax() > x
			&& other.y < GetYMax() && other.GetYMax() > y;
	}

	// 연산자 오버로딩
	friend std::ostream& operator<<(std::ostream& os, const Bound& bounds)
	{
		os << "(" << bounds.x << ", " << bounds.y << ")"
			<< "Width: " << bounds.width << " Height: " << bounds.height << "\n";

		return os;
	}

private:
	// 콘솔 좌표계 기준 위치
	int x = 0;
	int y = 0;

	// 크기
	int width = 1;
	int height = 1;

};

