#pragma once

#include "Creature.h"
#include "Potion.h"

class Player : public Creature
{
private:
	int m_level;

public:
	Player(std::string_view name);

	int getLevel() const { return m_level; }
	bool hasWon() const { return m_level >= 20; }

	void levelUp();
	void drinkPotion(Potion& potion);
};