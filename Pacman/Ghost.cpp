#include "stdafx.h"
#include "Ghost.h"
#include<string>

Ghost::Ghost(std::string name, KPlatform *plat) : Player (name,plat)
{

}

void Ghost::UpdateLogic(Player *player)
{
	int x = GetPositionX();
	int y = GetPositionY();
	float vel = 2;
	if (x % 20 == 0) {
		directionY = -1;
		directionX = 0;
	}
	else if ( x % 20 == 0) {
		directionY = 1;
		directionX = 0;
	}
	else if (y % 20 == 0) {
		directionX = -1;
		directionY = 0;
	}
	else if (y % 20 == 0) {
		directionX = 1;
		directionY = 0;
	}

	SetPositionX(x + vel);
}

Ghost::~Ghost()
{
}
