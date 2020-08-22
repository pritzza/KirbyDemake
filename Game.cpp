#include "Game.h"
#include <iostream>

Game::Game()
{
	gameLoop();
}

void Game::gameLoop()
{
	while (true)
	{
		gameData.stateMachine.processStateChange();

		std::cout << gameData.stateMachine.states.size();

		if (gameData.stateMachine.currentState() == nullptr)
		{
			std::cout << "current state was nullptr" << std::endl;
			continue;
		}

		gameData.stateMachine.currentState()->draw();
		gameData.stateMachine.currentState()->update();
		gameData.stateMachine.currentState()->handleInput();

		std::cout << std::endl;;
	}
}