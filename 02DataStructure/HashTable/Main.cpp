#include "HashTable.h"
#include <iostream>

int main()
{
	HashTable table;

	// 키-값 데이터 추가
	table.Add("Name", "1234245");

	// 중복 키 추가 확인
	if (!table.Add("Name", "1234245"))
	{
		std::cout << "중복\n";
	}

	table.Add("qqqq", "1234245");
	table.Add("eeee", "1234245");
	table.Add("wwww", "1234245");

	// 출력
	std::cout << "\nAll data\n";
	table.Print();

	// 검색
	std::string number;
	if (table.Find("Name", number))
	{
		std::cout << "\nSearch Result : Name" << number << "\n";
	}

	// 삭제
	if (table.Delete("eeee"))
	{
		std::cout << "eeee Delete\n";
	}

	// 출력
	std::cout << "\nRemain data\n";
	table.Print();
}