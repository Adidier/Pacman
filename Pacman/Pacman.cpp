// Pacman.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "KPlatform.h"

void InitGame()
{
	PooEngine::KPlatform *platform = new PooEngine::KPlatform("Pac-man");
}

void Inputs()
{

}

void UpdateLogic()
{

}

void UpdateScreen()
{

}
int main(int argc, char *argv[])
{
	bool finish = false;
	InitGame();

	while (!finish)
	{
		Inputs();
		UpdateLogic();
		UpdateScreen();
	}
    return 0;
}

