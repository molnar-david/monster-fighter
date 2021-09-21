#include "monster_fighter.h"
#include "random_number.h"
#include <iostream>

void onMonsterKilled(Player& player, const Monster& monster)
{
	player.levelUp();
	player.addGold(monster.getGold());

	std::cout << "You killed the " << monster.getName() << ".\n";
	std::cout << "You are now level " << player.getLevel() << ".\n";
	std::cout << "You found " << monster.getGold() << " gold.\n";

	int potionChance{ 30 };
	if (getRandomNumber(1, 100) <= potionChance)
	{
		Potion potion{ Potion::getRandomPotion() };

		char input{};

		do
		{
			std::cout << "You found a mythical potion! Do you want to drink it? [y/n]: ";
			std::cin >> input;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (input != 'y' && input != 'Y' && input != 'n' && input != 'N');

		if (input == 'y' || input == 'Y')
			player.drinkPotion(potion);
	}
}

void attackMonster(Player& player, Monster& monster)
{
	monster.reduceHealth(player.getDamage());
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";

	if (monster.isDead())
		onMonsterKilled(player, monster);
}

void attackPlayer(const Monster& monster, Player& player)
{
	// we killed the monster already, do nothing
	if (monster.isDead())
		return;

	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
}

void fightMonster(Player& player)
{
	Monster monster{ Monster::getRandomMonster() };

	std::cout << "\nYou have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")\n";

	while (!monster.isDead() && !player.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input{};
		std::cin >> input;

		// invalid input handling - user enters multiple characters
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// player wants to run
		if (input == 'r' || input == 'R')
		{
			// 50% chance to flee
			if (getRandomNumber(0, 1))
			{
				std::cout << "You successfully fled!\n";
				return;		// success ends the encounter
			}
			else
			{
				// player gets attacked upon failure
				std::cout << "You failed to flee.\n";
				attackPlayer(monster, player);
				continue;
			}
		}

		// player wants to fight
		if (input == 'f' || input == 'F')
		{
			attackMonster(player, monster);
			attackPlayer(monster, player);
		}
	}
}