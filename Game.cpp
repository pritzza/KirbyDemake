#include "Game.h"
#include <iostream>
#include "PlayState.h"
Game::Game()
{
	window.create(sf::VideoMode(800, 600), "Window", sf::Style::Default);

	window.setFramerateLimit(5);

	// Puts first gamestate into play
	gameData.stateMachine.addState(new PlayState(&gameData.stateMachine, &window), false);

	gameLoop();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asMilliseconds();

		gameData.stateMachine.processStateChange();

		//std::cout << "Currently: " << gameData.stateMachine.states.size() << " gameStates" << std::endl;

		if (gameData.stateMachine.currentState() == nullptr)
		{
			std::cout << "current state was nullptr" << std::endl;
			continue;
		}

		gameData.stateMachine.currentState()->handleInput();
		gameData.stateMachine.currentState()->update();

        window.clear(sf::Color::Black);

		gameData.stateMachine.currentState()->draw();

        window.display();

		std::cout << std::endl;
    }
}