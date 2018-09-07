#pragma once
#include "GameObject.h"
#include "Image.h"
#include <string>
#include <vector>
#include <map>
#include "KPlatform.h"

using namespace PooEngine;

class Player : public GameObject
{
protected:
	int width;
	int height;
	std::map<std::string, std::vector<Image *>> animations;
	KPlatform *platform;
	std::string state;
	int frame = { 0 };
public:
	Player(std::string name, KPlatform *plat);
	int loadPlayer(std::string name);
	int getWidth();
	void setWidth(int width);
	int getHeight();
	void setHeight(int height);
	void setRotation(float rotation);
	void UpdateRender();
};
