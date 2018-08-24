#include "stdafx.h"
#include "Map.h"
#include "KPlatform.h"
#include <fstream>

Map::Map(std::string name, PooEngine::KPlatform  *platform)
{
	background = new Image();
	this->platform=platform;
	background->LoadImage(name, PooEngine::KPlatform::renderer);
}

void Map::Render()
{
	background->getTexture();
	platform->RenderImage(background, 0, 0);
}

Map::~Map()
{
	delete background;
}

bool Map::loadMap(std::string name)
{
	fstream inputFile;
	inputFile.open(name.c_str());
	string buffer;
	while (!inputFile.eof()) {
		getline(inputFile, buffer);
		cout << buffer;
	}
	return true;
}