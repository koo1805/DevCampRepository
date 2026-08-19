#include <vector>
#include <algorithm>
#include <iostream>

// 정렬 조건에 사용할 함수 객체.
struct Greater
{
	bool operator()(int left, int right)
	{
		return left > right;
	}
};

struct Less
{
	bool operator()(int left, int right)
	{
		return left < right;
	}
};

int main()
{
	// 정렬에 사용할 벡터(동적 배열).
	std::vector<int> data = { 3, 2, 4, 5, 1, 6, 3, 4, 5, 6, 1, 10, };

	// 정렬.
	//Greater greater;
	//std::sort(data.begin(), data.end(), Less());

	// 람다를 정렬 조건에 사용.
	std::sort(
		data.begin(),
		data.end(),
		[](int left, int right)/* -> bool*/
		{
			return left < right;
		}
	);

	int result = 0;
	auto add = [&result](int value)
		{
			result += value;
		};

	add(10);
	add(20);

	std::cout << result << "\n";

	// 결과 출력.
	for (const int item : data)
	{
		std::cout << item << " ";
	}

	std::cout << "\n";
}