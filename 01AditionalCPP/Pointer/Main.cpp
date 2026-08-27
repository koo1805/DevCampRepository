#include <iostream>

// 함수를 통한 변경
void ChangeValue01(int data)
{
	data = 20;
}

void ChangeValue02(int* data)
{
	*data = 20;
}

int main()
{
	int num = 10;

	ChangeValue01(num);
	// num(10)값이 함수내의 data(10)에 복사
	// > data(10)이 data(20)으로 변경
	// > num(10)은 변하지 않음
	
	ChangeValue02(&num);
	// 함수의 매개변수가 역참조타입이라 주소연산자를 붙여야됨
	// num의 주소값을 data에 복사
	// *data에서 주소에 접근후 값 변경
	// num에 영향을 줌

	// 포인터 - 주소를 저장하는 변수
	int* pointer = &num;
	int* pointerB = nullptr;

	// 주소값 비교 - 같은 위치 인가?
	if (pointer == pointerB)
	{
		std::cout << "일치\n";
	}

	// 더블 포인터 - 주소를 저장
	// >> 포인터의 주소를 저장
	int** doublePointer = &pointer;

	// 삼차 포인터
	// >> 포인터를 저장하는 포인터의 주소 저장
	int*** triplePointer = &doublePointer;

	// 참조: 주소를 저장하는 것
	// 역참조 - 저장한 주소를 통해 접근하는 방법
	int value01 = *pointer;
	int value02 = **doublePointer;
	int value03 = ***triplePointer;


	std::cin.get();
}