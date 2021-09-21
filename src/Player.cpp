#include "Player.h"
#include <iostream>

Player::Player(std::string_view name)
	: Creature{ name, '@', 10, 1, 0 },
	m_level{ 1 }
{
}

void Player::levelUp()
{
	++m_level;
	++m_damage;
}

void Player::drinkPotion(Potion& potion)
{
	std::cout << "You drank a " << potion.getName() << ". ";
	int effect{};

	switch (potion.getType())
	{
	case Potion::Type::HEALTH:
		effect = static_cast<int>(potion.getSize()) * 2 + 1;		// +1, +3 or +5 health respectively
		m_health += effect;
		std::cout << '+' << effect << " health!\n";
		break;

	case Potion::Type::STRENGTH:
		effect = static_cast<int>(potion.getSize()) + 1;			// +1, +2 or +3 damage respectively
		m_damage += effect;
		std::cout << '+' << effect << " damage!\n";
		break;

	case Potion::Type::POISON:
		effect = static_cast<int>(potion.getSize()) + 1;			// -1, -2 or -3 health respectively
		m_health -= effect;
		std::cout << '-' << effect << " health!\n";
		break;

	case Potion::Type::MAX_TYPES:
		break;
	}
}