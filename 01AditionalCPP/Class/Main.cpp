#include <iostream>

class Character
{
public:
	virtual ~Character() = default;

	float attack = 10.0f;

	virtual void Attack()
	{
		//std::cout << "\n메인 캐릭터 공격\n";
		std::cout << "attack: " << attack << "\n";
	}
};

class Warrior : public Character
{
public:
	float armor = 50.0f;

	virtual void Attack() override
	{
		std::cout << "\n=== Warrior ===\n";
		Character::Attack();

		std::cout << "armor: " << armor << "\n";
	}

	void UseShield()
	{
		std::cout << "쉴드 사용";
	}
};

class Mage : public Character
{
public:
	float mana = 100.0f;

	virtual void Attack() override
	{
		std::cout << "\n=== Mage ===\n";
		Character::Attack();

		std::cout << "mana: " << mana << "\n";
	}
};

int main()
{
	Character character;
	character.attack = 20.0f;
	character.Attack();

	// 포인터로 객체 사용
	Character* pointer = &character;
	pointer->attack = 30.0f;
	pointer->Attack();
	// -> 연산자는 역참조를 대신함
	(*pointer).attack = 40.0f;
	(*pointer).Attack();

	// 캐릭터를 상속한 워리어 객체 생성 (IS-A)	-> 워리어는 캐릭터다
	// IS-A의 성립 방향은 한 방향				-> Character는 워리어가 아님
	Warrior warrior;
	warrior.attack = 50.0f;
	warrior.armor = 5.0f;
	warrior.Attack();

	Mage mage;
	mage.mana = 50.0f;
	mage.attack = 30.0f;
	mage.Attack();

	// 캐릭터 포인터 -> 업캐스팅 (상위 계층으로 형변환)
	// 항상 안전하기 때문에 형변환 연산을 생략해도 됨
	Character* mainCharacter = &mage;
	mainCharacter->Attack();

	mainCharacter = &warrior;
	mainCharacter->Attack();

	// 모든 캐릭터 타입을 배열로 관리하고 싶음
	Character* level[3] = {};
	level[0] = &character;
	level[1] = &warrior;
	level[2] = &mage;

	std::cout << "\n==============배열관리==============\n";

	for (Character* const character : level)
	{
		character->Attack();

		// Warrior로 형변환 (Down-casting)
		//Warrior* warrior = (Warrior*)character;
		Warrior* warrior = dynamic_cast<Warrior*>(character);
		if (warrior)
		{
			warrior->UseShield();
		}
	}
}