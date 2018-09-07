#pragma once
#include "Player.h"
#include <string>
#include "KPlatform.h"
#include "Player.h"

using namespace PooEngine;

class Ghost : public Player
{
private:
	int directionX = 0;
	int directionY = 0;
public:
	Ghost(std::string name, KPlatform *plat);
	void UpdateLogic(Player *player);
	~Ghost();
};

