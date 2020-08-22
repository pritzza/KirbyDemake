#include "PlayState.h"
#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>

void PlayState::handleInput()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Space)
			{
				std::cout << "play calling addState type menu" << std::endl;
				stateMachine->addState(new MenuState(stateMachine, window), true);
			}
			break;
		}
	}

	std::cout << "play input" << std::endl;
}
void PlayState::update() 
{
	std::cout << "play update" << std::endl;
}
void PlayState::draw() 
{
	std::cout << "play draw" << std::endl;
}