#include "stdafx.h"
#include "GameState.h"
#include "Actor.h"

void GameState::InitGame()
{
	platform = new PooEngine::KPlatform("Pac-man");
	player = new Actor("Assets/pacman.txt", platform);
	ghostGreen = new Ghost("Assets/ghost_green.txt", platform);

	map = new Map("Assets/levelBackground.png", platform);
	map->loadMap("Assets/map.txt");
	map->Render();
	player->SetPositionX(map->GetPosPlayerX());
	player->SetPositionY(map->GetPosPlayerY());
	ghostGreen->SetPositionX(160);
	ghostGreen->SetPositionY(160);
	
}

int GameState::Inputs()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		return 0;


	int x = player->GetPositionX();
	int y = player->GetPositionY();

	if (currentKeyStates[SDL_SCANCODE_W] && x%20 ==0) {
		directionY = -1;
		directionX = 0;
	}
	else if (currentKeyStates[SDL_SCANCODE_S] && x%20 == 0) {
		directionY = 1;
		directionX = 0;
	}
	else if (currentKeyStates[SDL_SCANCODE_A] && y%20 == 0) {
		directionX = -1;
		directionY = 0;
	}
	else if (currentKeyStates[SDL_SCANCODE_D] && y%20 == 0) {
		directionX = 1;
		directionY = 0;
	}


}

void GameState::UpdateLogic()
{
	float x = player->GetPositionX();
	float y = player->GetPositionY();
	float vel = 2.0;

	if (directionY < 0 )
	{
		int tileUp = map->GetTypeTile(ceil(y/20)-1, ceil(x/20));
		cout << "Arriba  " << x << " " << y << endl;
		if (tileUp > 0 )
		{
			player->SetPositionY(y - vel);
			player->setRotation(270);
		}
	}

	else if (directionY > 0 )
	{
		int tileUp = map->GetTypeTile(floor(y / 20) + 1, ceil(x / 20));
		cout << "Arriba  " << x << " " << y << endl;
		if (tileUp > 0)
		{
			player->SetPositionY(y + vel);
			player->setRotation(90);
		}
	}

	if (directionX < 0 )
	{
		int tileLeft = -1;
		tileLeft = map->GetTypeTile((y / 20), ceil(x / 20) - 1);

		cout << "Izquierda" << x << " " << y << endl;
		if (tileLeft > 0)
		{
			player->SetPositionX(x - vel);
			player->setRotation(180);
		}
	}

	if (directionX > 0)
	{
		int tileLeft = -1;
		tileLeft = map->GetTypeTile((y / 20), floor(x / 20) + 1);

		cout << "Derecha" << x << " " << y << endl;
		if (tileLeft > 0)
		{
			player->SetPositionX(x + vel);
			player->setRotation(0);
		}
	}


	if(map->GetTypeTile(y / 20, x / 20)==2)
		map->SetTypeTile(y / 20, x / 20, 4);

	if (map->GetTypeTile(y / 20, x / 20) == 3)
	{
		player->SetPositionX(300);
	}
		
	if (map->GetTypeTile(y / 20, x / 20) == 7)
	{
		player->SetPositionX(20);
	}

	
	if (map->CheckPellets())
	{
		exit(0);
	}
}

void GameState::UpdateScreen()
{
	map->Render();
	player->UpdateRender();
	ghostGreen->UpdateRender();
	ghostGreen->UpdateLogic(player,map);
	platform->RenderPresent();
	platform->RenderClear();
}

