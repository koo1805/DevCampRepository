#include <iostream>
//#include <array>
//#include <vector>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 배열을 전달 받아서 원소를 출력하는 함수.
void PrintArray(int* array, int count)
{
	for (int ix = 0; ix < count; ++ix)
	{
		std::cout << array[ix] << " ";
	}
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//std::array<int, 5> stdArray;
	//stdArray.size();

	// 배열.
	const int length = 5;
	int array[length] = {};
	//memset(array, 0, sizeof(int) * length);

	// 동적 배열.
	int* dArray = new int[length];

	//dArray[0] = 10;

	// 메모리 해제.
	delete[] dArray;

	// 배열을 포인터로 다루기.
	int* ptr = array;
	*(ptr + 2) = 30;		// 포인터의 덧셈은 메모리 점프.

	// 배열 순회.
	for (int ix = 0; ix < length; ++ix)
	{
		array[ix] = ix + 1;
	}

	// Range-Based Loop (범위 기반 루프).
	// c# - foreach.
	//for (const int value : array)
	//{
	//	std::cout << value << " ";
	//}

	PrintArray(array, length);

	std::cout << "\n";

	std::cin.get();
}