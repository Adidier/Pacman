// Pacman.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "GameState.h"

int main(int argc, char *argv[])
{
	bool finish = false;
	GameState pacman;
	pacman.InitGame();
	
	while (!finish)
	{
		pacman.Inputs();
		pacman.UpdateLogic();
		pacman.UpdateScreen();
	}
    return 0;
}

