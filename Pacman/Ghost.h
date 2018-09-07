#pragma once
#include "Actor.h"
#include <string>
#include "KPlatform.h"
#include "Map.h"

using namespace PooEngine;

class Ghost : public Actor
{
private:
	int directionX = 0;
	int directionY = 0;
public:
	Ghost(std::string name, KPlatform *plat);
	void UpdateLogic(Actor *player, Map * map);
	~Ghost();
};

