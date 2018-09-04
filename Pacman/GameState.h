#pragma once
#include "KPlatform.h"
#include "Map.h"
#include "Player.h"

class GameState {
private:
	Map *map;
	PooEngine::KPlatform *platform;
	Player *player;
	int frameRate = 0;
	int directionX = 0;
	int directionY = 0;
public:
	void InitGame();
	int Inputs();
	void UpdateLogic();
	void UpdateScreen();
};
