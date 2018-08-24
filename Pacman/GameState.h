#pragma once
#include "KPlatform.h"
#include "Map.h"

class GameState {
private:
	Map * map;
	PooEngine::KPlatform *platform;
public:
	void InitGame();
	void Inputs();
	void UpdateLogic();
	void UpdateScreen();
};
