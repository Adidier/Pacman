#pragma once

#include "Image.h"
#include <string>
#include "KPlatform.h"

class Map
{
private:
	Image * background;
	PooEngine::KPlatform  *platform;
	
public:
	Map(std::string name, PooEngine::KPlatform  *platform);
	void Render();
	bool loadMap(std::string name);
	~Map();
};

