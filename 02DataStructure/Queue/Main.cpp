#include "Queue.h"
#include <iostream>

int main()
{
	const int count = 5;

	// 큐 객체 생성
	Queue<int, count> queue;

	// 큐에 데이터 저장
	for (int ix = 0; ix < count; ++ix)
	{
		if (!queue.Enqueue(ix + 1))
		{
			std::cout << "save failed!";
		}
	}

	// 큐에 저장된 데이터 출력
	queue.Print();

	// 맨 앞에 데이터 읽기
	int firstValue = 0;
	if (queue.Front(firstValue))
	{
		std::cout << "1st data: " << firstValue << "\n";
	}

	// 데이터 출력
	int outValue = 0;
	if (queue.Dequeue(outValue))
	{
		std::cout << "output: " << outValue << "\n";
	}

	queue.Print();
}