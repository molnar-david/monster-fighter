#pragma once

#include "Creature.h"

class Monster : public Creature
{
public:
	enum class Type
	{
		DRAGON,			// 0
		ORC,			// 1
		SLIME,			// 2
		MAX_TYPES		// 3
	};

private:
	// monster lookup table
	static const Creature& getDefaultCreature(Type type);

public:
	Monster(Type type);

	static Monster getRandomMonster();
};