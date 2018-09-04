#include "stdafx.h"
#include "GameState.h"
#include "Player.h"

void GameState::InitGame()
{
	platform = new PooEngine::KPlatform("Pac-man");
	player = new Player("Assets/pacman.txt", platform);
	map = new Map("Assets/levelBackground.png", platform);
	map->loadMap("Assets/map.txt");
	map->Render();
	player->SetPositionX(map->GetPosPlayerX());
	player->SetPositionY(map->GetPosPlayerY());
}

int GameState::Inputs()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

	float x = player->GetPositionX();
	float y = player->GetPositionY();
	float vel = 1.5;

	if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		return 0;

	if (currentKeyStates[SDL_SCANCODE_W] || directionY == -1) {
		int tileUp = map->GetTypeTile(ceil((y - 20) / 20), floor(x / 20));
		cout << "Arriba" << x<< " " <<y<< endl;
		if (tileUp > 0)
		{
			player->SetPositionY(y - vel);
			directionY = -1;
			directionX = 0;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_S] || directionY == 1) {
		cout << "Abajo" << x << " " << y << endl;
		int tileDown = map->GetTypeTile(floor((y + 20) / 20), floor(x / 20));
		if (tileDown > 0)
		{
			player->SetPositionY(y + vel);
			directionY = 1;
			directionX = 0;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_A]|| directionX == -1) {
		int tileLeft = map->GetTypeTile(floor(y / 20), ceil((x - 20) / 20));
		cout << "Izquierda" << x << " " << y << endl;
		if (tileLeft > 0)
		{
			player->SetPositionX(x - vel);
			directionX = -1;
			directionY = 0;
		}
	}
	if (currentKeyStates[SDL_SCANCODE_D] || directionX == 1) {
		cout << "Derecha" << x + vel << " " << y << endl;
		int tileRight = map->GetTypeTile(floor(y / 20), floor((x + 20) / 20));
		if (tileRight > 0)
		{
			player->SetPositionX(x + vel);
			directionX = 1;
			directionY = 0;
		}
	}

	if(map->GetTypeTile(y / 20, x / 20)!=0)
		map->SetTypeTile(y / 20, x / 20, 4);
}

void GameState::UpdateLogic()
{

	if (map->CheckPellets())
	{
		exit(0);
	}
}

void GameState::UpdateScreen()
{
	frameRate++;

		map->Render();
		player->UpdateRender();
		platform->RenderPresent();
		platform->RenderClear();
		frameRate = 0;
}