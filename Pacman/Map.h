#pragma once

#include "Image.h"
#include <string>
#include "KPlatform.h"
#include <vector>

class Map
{
private:
	Image * background;
	Image * wall;//0
	Image * superPellet;//1
	Image * pellet;//2
	Image * warp;//3
	Image * empty;//4
	


	PooEngine::KPlatform  *platform;
	std::vector<std::vector<int>> map;
public:
	Map(std::string name, PooEngine::KPlatform  *platform);
	void Render();
	bool loadMap(std::string name);
	~Map();
};

