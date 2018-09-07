#pragma once
#include "KPlatform.h"
#include "Map.h"
#include "Actor.h"
#include "Ghost.h"

class GameState {
private:
	Map *map;
	PooEngine::KPlatform *platform;
	Actor *player;
	Ghost *ghostGreen;
	int frameRate = 0;
	int directionX = 0;
	int directionY = 0;
public:
	void InitGame();
	int Inputs();
	void UpdateLogic();
	void UpdateScreen();
};
