#include <iostream>
#include <memory>
#include <vector>

class Actor
{
public:
	virtual ~Actor() = default;
};

class Player : public Actor
{
};

int main()
{
	std::shared_ptr<Actor> actor = std::make_shared<Actor>();
	std::shared_ptr<Player> player = std::make_shared<Player>();
	
	// shared_ptr은 소유권 공유 가능.
	// 참조(사용) 회수를 추적해야 함.
	std::shared_ptr<Player> otherPlayer = player;

	std::vector<int> test;
	test.push_back(10);
	test.emplace_back(10);
}