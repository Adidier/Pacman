#include "stdafx.h"
#include "GameState.h"

void GameState::InitGame()
{
	platform = new PooEngine::KPlatform("Pac-man");
	map = new Map("Assets/levelBackground.png", platform);
	map->loadMap("Assets/map1.txt");
}

void GameState::Inputs()
{

}

void GameState::UpdateLogic()
{

}

void GameState::UpdateScreen()
{
	map->Render();
	platform->RenderPresent();
	platform->RenderClear();
}