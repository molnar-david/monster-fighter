#include "Monster.h"
#include "random_number.h"
#include <array>

const Creature& Monster::getDefaultCreature(Type type)
{
	static const std::array<Creature, static_cast<std::size_t>(Type::MAX_TYPES)> monsterData{
		{ {"dragon", 'D', 20, 4, 100},
		  {"orc", 'o', 4, 2, 25},
		  {"slime", 's', 1, 1, 10} }
	};

	return monsterData.at(static_cast<std::size_t>(type));
}

Monster::Monster(Type type)
	: Creature{ Monster::getDefaultCreature(type) }
{
}

Monster Monster::getRandomMonster()
{
	int num{ getRandomNumber(0, static_cast<int>(Type::MAX_TYPES) - 1) };

	return Monster{ static_cast<Type>(num) };
}