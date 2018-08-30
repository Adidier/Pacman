#include "stdafx.h"
#include "Player.h"
#include "Image.h"
#include "KPlatform.h"
#include <fstream>
using namespace std;
using namespace PooEngine;

Player::Player(std::string name, KPlatform *plat)
{
	//"Images/paddle.png"
	//image.LoadImage(name, KPlatform::renderer);
	//SDL_Texture *t = image.getTexture();
	loadPlayer(name);
	platform = plat;
	state = "idle";
	//SDL_QueryTexture(image.getTexture(), NULL, NULL, &width, &height);
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

Player::~Player()
{
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

void Player::UpdateRender()
{
	platform->RenderImage(animations[state][frame], x, y); //obtener la direccion de memoria &
	frame++;
	if (frame >= animations[state].size())
		frame = 0;
}