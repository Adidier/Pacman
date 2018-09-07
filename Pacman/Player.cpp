#include "stdafx.h"
#include "Player.h"
#include "Image.h"
#include "KPlatform.h"
#include <fstream>
using namespace std;
using namespace PooEngine;

Player::Player(std::string name, KPlatform *plat)
{
	loadPlayer(name);
	platform = plat;
	state = "idle";
}

int Player::loadPlayer(std::string name)
{
	fstream inputFile;
	inputFile.open(name.c_str());
	if (!inputFile.is_open())
		return 0;
	string buffer;
	while (!inputFile.eof()) {
		getline(inputFile, buffer);
		int nFrames=std::stoi(buffer);
		getline(inputFile, buffer);
		std::string anim = buffer;
		for (int i = 0; i < nFrames; i++)
		{
			getline(inputFile, buffer);
			Image *frame= new Image();
			frame->LoadImage(buffer, PooEngine::KPlatform::renderer);
			animations[anim].push_back(frame);
		}
	}

	return 1;
}

int Player::getWidth()
{
	return width;
}

void Player::setWidth(int newWidth)
{
	this->width = newWidth;
}

int Player::getHeight()
{
	return height;
}

void Player::setHeight(int newHeight)
{
	this->height = newHeight;
}

void Player::setRotation(float rotation)
{
	this->rotation = rotation;
}

void Player::UpdateRender()
{
	platform->RenderImage(animations[state][frame], x, y,rotation); 
	frame++;
	if (frame >= animations[state].size())
		frame = 0;




}