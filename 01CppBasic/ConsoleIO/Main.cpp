// std::cout / std::cin 사용하기 위해 필요함.
#include <iostream>

// 참고로 using namespace std; -> 수업에서는 사용 안함.
// std는 범위가 너무 큼.

// 진입점(Entry Point).
int main()
{
	std::cout << "Hello Game Programming.\n";

	// 프로그램 바로 종료되지 말라고 추가.
	std::cin.get();
	// 생략 가능.
	//return 0;
}