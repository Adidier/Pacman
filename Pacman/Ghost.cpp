#include "stdafx.h"
#include "Ghost.h"
#include<string>

Ghost::Ghost(std::string name, KPlatform *plat) : Actor (name,plat)
{

}

void Ghost::UpdateLogic(Actor *player, Map * map)
{
	if (rand() % 10 > 5)
		return;

	directionX = 0;
	directionY = 0;
	float x = GetPositionX();
	float xPlayer = player->GetPositionX();

	directionX = x - xPlayer;

	float y = GetPositionY();
	float yPlayer = player->GetPositionY();

	directionY = y - yPlayer;

	float vel = 2;

	int tileDown = map->GetTypeTile(floor(y / 20) + 1, ceil(x / 20));
	int tileUp = map->GetTypeTile(ceil(y / 20) - 1, ceil(x / 20));
	int tileRight = map->GetTypeTile((y / 20), floor(x / 20) + 1);
	int tileLeft = map->GetTypeTile((y / 20), ceil(x / 20) - 1);


	if (directionX>0 && tileLeft>0 ){//&& x % 20 == 0) {
		this->SetPositionX(x - vel);

	}
	else if (directionX<0 && tileRight>0) {//&& x % 20 == 0) {
		this->SetPositionX(x + vel);
	}
	else if (directionY < 0 && tileDown > 0)
	{
		this->SetPositionY(y + vel);
	}
	else if (directionY > 0 && tileUp > 0)
	{
		this->SetPositionY(y - vel);
	}
	/*else if ( x % 20 == 0) {
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
*/
	//SetPositionX(x + vel);
}

Ghost::~Ghost()
{
}
