#include "Player.h"
#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> test;

	Player player1;
	Player player2("Ronnie");
	Player player3(player2);

	Player player4 = player3;
}