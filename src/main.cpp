#include "monster_fighter.h"
#include <iostream>
#include <limits>
#include <random>

int main()
{
	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	// invalid input handling - user enters string with whitespace
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	Player player{ playerName };

	std::cout << "Welcome, " << player.getName() << "!\n";
	std::cout << "You have to reach level 20 in order to become an ultimate fighter and win the game.\n";
	std::cout << "Good luck!\n";

	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // get rid of first result

	// main game loop
	while (!player.isDead() && !player.hasWon())
		fightMonster(player);

	if (player.isDead())
	{
		std::cout << "\nYou died at level " << player.getLevel() << " with " << player.getGold() << " gold.\n";

		if (player.getGold() == 0)
		{
			std::cout << "Too bad!\n";
		}
		else
		{
			std::cout << "Too bad you can't take it with you!\n";
		}
	}
	else
	{
		std::cout << "\nYou reached level 20 and won the game with " << player.getGold() << " gold!\n";
		std::cout << "Congratulations!\n";
	}

	return 0;
}