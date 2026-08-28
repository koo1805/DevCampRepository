#include <iostream>

// 배열의 이름은 포인터인가? 
// 결론 > 아니다
//

int main()
{
	// 배열
	const int length = 5;
	int array[length] = { 1,2,3,4,5 };

	// 포안터 배열 > 배열의 이름은 배열의 첫 원소의 주소를 반환
	int* pointer01 = array;
	int* pointer02 = &array[0];

	// 포인터 덧셈 > 메모리 점프
	// 점프의 간격은 포인터 타입 크기만큼 (int 4바이트)
	// 예시
	// {1, 2, 3, 4, 5}
	// 해당 포인터에 1을 더하면 원래 타입인 int 4바이트 뒤의 주소값이 나옴
	
	/*
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << ix << " " << &array[ix] << "\n";
		std::cout << ix << " " << (pointer01 + ix) << "\n\n";
	}		//*/

	// 배열 요소에 10 곱하기
	for (int ix = 0; ix < length; ++ix)
	{
		//array[ix] *= 10;

		// 포인터로
		*(pointer01 + ix) *= 10;
	}

	/*
	// 배열의 이름은 포인터는 아님 (명확하게는)
	auto arraySize = sizeof(array);
	auto pointerSize = sizeof(pointer01);

	if (arraySize != pointerSize)
	{
		std::cout << "둘은 다름\n";
		std::cout << "arraySize: " << arraySize << "\n";
		std::cout << "pointerSize: " << pointerSize << "\n\n";
	}
	std::cout << "----------------------------------------------------------------------\n\n";

	std::cout << "pointer01: " << pointer01 << "\n";
	std::cout << "array:     " << array << "\n";
	std::cout << "pointer02: " << pointer02 << "\n";
	std::cout << "&array[0]: " << &array[0] << "\n";
	std::cout << "&array[2]: " << &array[2] << "\n";		//*/

	std::cin.get();
}