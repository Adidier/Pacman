#include "stdafx.h"
#include "GameState.h"
#include "Player.h"

void GameState::InitGame()
{
	platform = new PooEngine::KPlatform("Pac-man");
	map = new Map("Assets/levelBackground.png", platform);
	map->loadMap("Assets/map1.txt");

	player = new Player("Assets/pacman.txt", platform);
}

int GameState::Inputs()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_ESCAPE])
		return 0;
	//Player 1 controls:
	if (currentKeyStates[SDL_SCANCODE_W]) {
		cout << "Arriba" << endl;
		return 1;
	}
	if (currentKeyStates[SDL_SCANCODE_S]) {
		cout << "Abajo" << endl;
		return 1;
	}
	if (currentKeyStates[SDL_SCANCODE_A]) {
		cout << "Izquierda" << endl;
		return 1;
	}
	if (currentKeyStates[SDL_SCANCODE_D]) {
		cout << "Derecha" << endl;
		return 1;
	}

}

void GameState::UpdateLogic()
{

}

void GameState::UpdateScreen()
{
	frameRate++;
	if (frameRate >= 800000)
	{
		map->Render();
		player->UpdateRender();
		platform->RenderPresent();
		platform->RenderClear();
		frameRate = 0;
	}
}