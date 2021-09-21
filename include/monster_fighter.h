#pragma once

#include "Player.h"
#include "Monster.h"

void onMonsterKilled(Player& player, const Monster& monster);
void attackMonster(Player& player, Monster& monster);
void attackPlayer(const Monster& monster, Player& player);
void fightMonster(Player& player);