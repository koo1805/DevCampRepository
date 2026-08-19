#include "CraftObject.h"
#include <iostream>

//#define TO_NAME(x) #x
//#define CLASS_NAME(type)					\
//	public:									\
//	virtual const char* ClassName() const	\
//	{										\
//		return TO_NAME(type);				\
//	}
//
//class Actor
//{
//	CLASS_NAME(Actor)
//
//public:
//	static size_t TypeId()
//	{
//		// 정적 지역 변수.
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//};
//
//class Player : public Actor
//{
//	CLASS_NAME(Player)
//
//public:
//	static size_t TypeId()
//	{
//		// 정적 지역 변수.
//		static int runTimeTypeId = 0;
//		return reinterpret_cast<size_t>(&runTimeTypeId);
//	}
//};

class Actor : public CraftObject
{
	// 커스텀 타입 기능 제공을 위해 매크로 배치.
	TYPE_DECLARATIONS(Actor, CraftObject)
};

class Player : public Actor
{
	TYPE_DECLARATIONS(Player, Actor)
};

class Camera : public Actor
{
	TYPE_DECLARATIONS(Camera, Actor)
};

int main()
{
	//std::shared_ptr<Actor> player = std::make_shared<Player>();
	std::shared_ptr<Actor> camera = std::make_shared<Camera>();
	std::shared_ptr<Player> targetPlayer = Cast<Player>(camera);
	if (targetPlayer)
	{
		std::cout << "형변환 성공\n";
	}
	else
	{
		std::cout << "형변환 실패\n";
	}

	//Actor* actor = new Actor();
	//Actor* player = new Player();

	//std::cout << actor->ClassName() << "\n";
	//std::cout << player->ClassName() << "\n";

	// 원시 문자열 비교.
	// strcmp 구현해보기.
	//if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	//{
	//	std::cout << "두 타입이 같음.\n";
	//}
	//else
	//{
	//	std::cout << "두 타입이 다름.\n";
	//}

	//// 타입 ID로 비교.
	//if (actor->TypeId() == Player::TypeId())
	//{
	//	std::cout << "두 타입이 같음.\n";
	//}
	//else
	//{
	//	std::cout << "두 타입이 다름.\n";
	//}

	//delete actor;
	//actor = nullptr;

	//delete player;
	//player = nullptr;
}