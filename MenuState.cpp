#include "MenuState.h"
#include "PlayState.h"
#include "GameStateManager.h"
#include <iostream>

MenuState::MenuState(GameStateManager* stateMachine, sf::RenderWindow* window) : GameState{ stateMachine, window }
{
	shape.setRadius(150);
	shape.setOutlineColor(sf::Color::Red);
	shape.setOutlineThickness(5);
	shape.setPosition(10, 20);
}

void MenuState::handleInput()
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
				std::cout << "menu calling addState type play" << std::endl;
				stateMachine->addState(new PlayState(stateMachine, window), true);
			}
			break;
		}
	}

	std::cout << "menu input" << std::endl;
}
void MenuState::update()
{
	std::cout << "menu update" << std::endl;
}
void MenuState::draw()
{
	window->draw(shape);


	std::cout << "menu draw" << std::endl;

}