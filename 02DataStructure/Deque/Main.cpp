#include "Deque.h"
#include <iostream>

int main()
{
	Deque<int, 10> deque;

	for (int ix = 1; ix <= 10; ++ix)
	{
		if (ix % 2 == 0)
		{
			deque.AddFront(ix);
		}
		else
		{
			deque.AddRear(ix);
		}
	}

	deque.Print();
}