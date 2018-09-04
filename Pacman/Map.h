#pragma once

#include "Image.h"
#include <string>
#include "KPlatform.h"
#include <vector>
#include "Player.h"

class Map
{
private:
	Image * background;
	Image * wall;//0
	Image * superPellet;//1
	Image * pellet;//2
	Image * warp;//3
	Image * empty;//4
	int positionPlayerX;
	int positionPlayerY;
	PooEngine::KPlatform  *platform;
	std::vector<std::vector<int>> map;
public:
	Map(std::string name, PooEngine::KPlatform  *platform);
	void Render();
	bool loadMap(std::string name);
	int GetPosPlayerX();
	int GetPosPlayerY();
	int GetTypeTile(int x,int y);
	void SetTypeTile(int x, int y, int type);
	int CheckPellets();
	~Map();
};

