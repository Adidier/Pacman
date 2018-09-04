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

int Map::CheckPellets()
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 2)
				return 0;
		}
	}
	return 1;
}


void Map::Render()
{
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
				case 6:
					positionPlayerX=j*20;
					positionPlayerY=i*20;
				break;
			}
		}
	}
}

int Map::GetPosPlayerX()
{
	return positionPlayerX;
}

int Map::GetPosPlayerY()
{
	return positionPlayerY;
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

int Map::GetTypeTile(int x, int y)
{
	if(x>=0 && x<map.size() && y >= 0 && y<map[x].size())
		return map[x][y];

	return -1;
}

void Map::SetTypeTile(int x, int y,int type)
{

	if (x >= 0 && x<map.size() && y >= 0 && y<map[x].size())
		map[x][y] = type;
}