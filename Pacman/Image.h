#pragma once
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

class Image
{
private:
	SDL_Texture * image;
	std::string name;
public:
	void LoadImage(std::string name, SDL_Renderer *renderer);
	SDL_Texture *getTexture();
};