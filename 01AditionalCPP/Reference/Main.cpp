#include <iostream>

// 컴파일러: 
// 원래 기계어(하드웨어에 종속적)로 코딩			종속적? > 인텔은 인텔 컴파일러/ AMD는 AMD컴파일러 등등 제조사에 따라 다름
// > 어셈블러(하드웨어에 종속적) Asembly
// > 컴파일러(C 언어/UNIX)
// 
//

// void A( int* const num) > 주소값은 변경하지 말고 그 안에 접근해서 변경
void ChangeNum(int* number)
{
	*number = *number * 100;
	number = nullptr;
}

int main()
{
	int num = 10;

	ChangeNum(&num);
	std::cout << num << "\n";

	// 포인터
	int* pointer = &num;
	*pointer = 20;
	std::cout << num << "\n";				// 역참조 활용 값 변경


	// 참조 (LValue Reference) 변수
	int& reference01 = num;
	reference01 = 30;
	std::cout << num << "\n";				// 값 변경

	int& reference02 = *pointer;
	std::cout << reference02 << "\n";

	// 한 공간을 다수의 이름으로 대응 : 별칭
	// 레퍼런스는 주소를 읽는 목적이 아님
	// 래퍼런스는 중간에 다른 변수로 참조할 수 없음	>	처음 참조한 그 변수로 고정됨
	// 포인터는 중간에 다른 값으로 참조가능			>	포인터에 const를 붙이면 참조불가 비슷하게 됨
	// num -> [10] <- reference
	std::cout << &num << "\n";
	std::cout << &pointer << "\n";
	std::cout << &reference01 << "\n";
	std::cout << &reference02 << "\n";

}