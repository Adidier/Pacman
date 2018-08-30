#include "stdafx.h"
#include "Map.h"
#include "KPlatform.h"
#include <fstream>

Map::Map(std::string name, PooEngine::KPlatform  *platform)
{
	background = new Image();
	this->platform=platform;
	background->LoadImage(name, PooEngine::KPlatform::renderer);

	wall = new Image();//0
	superPellet = new Image();//1
	pellet = new Image();//2
	warp = new Image();//3
	empty = new Image();//4

	wall->LoadImage("Assets/0.png", PooEngine::KPlatform::renderer);
	superPellet->LoadImage("Assets/1.png", PooEngine::KPlatform::renderer);
	pellet->LoadImage("Assets/2.png", PooEngine::KPlatform::renderer);
	warp->LoadImage("Assets/3.png", PooEngine::KPlatform::renderer);
	empty->LoadImage("Assets/4.png", PooEngine::KPlatform::renderer);
}

void Map::Render()
{
//	background->getTexture();
	for (int i=0;i<map.size();i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			switch (map[i][j])
			{
				case 0:
					platform->RenderImage(wall, j *20, i * 20);
				break;
				case 1:
					platform->RenderImage(superPellet, j * 20, i * 20);
				break;
				case 2:
					platform->RenderImage(pellet, j * 20, i * 20);
				break;
				case 3:
					platform->RenderImage(warp, j * 20, i * 20);
				break;
				case 4:
					platform->RenderImage(empty, j * 20, i * 20);
				break;
			}
		}
	}
	
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
		cout << buffer<<endl;
		vector<int> row;
		for (int i = 0; i < buffer.length(); i++)
		{
			if (buffer[i] == ',')
				continue;
			else if (buffer[i] >= '0'&&buffer[i] <= '9')
				row.push_back(int(buffer[i] - '0'));
		}
		map.push_back(row);
	}
	return true;
}