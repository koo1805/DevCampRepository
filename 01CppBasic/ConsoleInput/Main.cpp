#include <iostream>

int main()
{
	// 입력.
	// 숫자 입력 요청 -> 숫자가 아니면 다시 요청(예외처리).
	int value = 0;

	// 무한 루프 작성 방법.
	// 1. 종료 조건을 확인.
	while (true)
	{
		// 검증용 문자 버퍼.
		char buffer[50] = {};
		std::cout << "0이 아닌 숫자를 입력하세요(첫 번째): ";
		std::cin >> buffer;

		// 검증.
		// int -> 32bit? 질문..?yes/no?
		if ((value = atoi(buffer)) == 0)
		{
			std::cout << "숫자를 입력하세요\n";
		}
		// 숫자 입력이 제대로 된 경우.
		else
		{
			// 루프 종료.
			break;
		}
	}

	int value2 = 0;
	std::cout << "0이 아닌 숫자를 입력하세요(두 번째): ";
	std::cin >> value2;

	std::cout
		<< "입력한 두 수의 합은 "
		<< (value + value2)
		<< "입니다\n";

	//std::cout << "입력하신 숫자는 " << value << "입니다.\n";

	std::cin.get();
}