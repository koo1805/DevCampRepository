#include <iostream>
#include <memory>	// 스마트 포인터 사용을 위해 필요함.

class Actor
{
public:
	virtual ~Actor() = default;
};

class Player : public Actor
{
public:
	Player()
	{
		std::cout << "Player constructed.\n";
	}

	~Player()
	{
		std::cout << "Player destroyed.\n";
	}

	void Attack() const
	{
		std::cout << "Player attacks.\n";
	}
};

template<typename T>
class Data
{
public:

	T* operator->()
	{
		return data;
	}

private:
	T* data = nullptr;
};

// 함수로 전달 받기.
void AttackPlayer(Player* player)
{
	player->Attack();
	//delete player;
}

void AttackPlayer2(const Player& player)
{
	player.Attack();
}

void AttackPlayer3(const std::unique_ptr<Player>& player)
{
	player->Attack();
}

int main()
{
	// 스마트 포인터.
	// STL - Standard Template Library.
	std::unique_ptr<Player> player
		= std::make_unique<Player>();

	// 스마트 포인터 객체의 사용은 일반 포인터의 사용 방법과 같다.
	// -> 연산자로 참조 가능.
	player->Attack();

	// 레퍼런스(역참조) 방법도 기존 포인터와 동일.
	Player& playerRef = *player;

	// 다른 스마트 포인터.
	// unique_ptr은 소유권 공유가 안됨.
	//std::unique_ptr<Player> player2 = player;

	// 주소를 빌려서 사용하는 방법.
	// 1. RawPointer(원시 포인터)로 받아서 사용.
	// 위험! -> 실수로 delete를 할 수 있음.
	//Player* player2 = player.get();
	//delete player2;
	AttackPlayer(player.get());

	// 2. 레퍼런스로 전달 받기.
	// 원시 포인터보다 조금 더 안전한 방법.
	AttackPlayer2(*player);

	// 3. 스마트 포인터의 레퍼런스를 사용.
	// 3번 방법도 가능은 하나 unique_ptr 정의/사용 방식에 위배.
	AttackPlayer3(player);

	// unique_ptr의 소유권을 다른 곳으로 넘기는 방법.
	// ValueCategory와 연결.
	// 이전을 다른 곳으로 한 이후로는 기존에 사용하던 player를 사용하면 안됨.
	std::unique_ptr<Player> otherPlayer = std::move(player);
	// 이전을 한 뒤로는 기존 포인터를 리셋(초기화) 해주는 게 좋음.
	player.reset();
	if (player)
	{
	}

	std::cout << "End\n";
}