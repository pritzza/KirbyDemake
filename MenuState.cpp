#include "MenuState.h"
#include "PlayState.h"

#include "GameData.h"

#include <iostream>

MenuState::MenuState(GameData* data, sf::RenderWindow* window) : GameState (data, window)
{

}

void MenuState::init()
{

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
			if (event.key.code == sf::Keyboard::E)
			{
				//std::cout << "menu calling addState type play" << std::endl;
				data->stateMachine.addState(new PlayState(data, window), true);
			}
			break;
		}
	}

	//std::cout << "menu input" << std::endl;
}
void MenuState::update()
{
	//std::cout << "menu update" << std::endl;
}
void MenuState::draw()
{
	//std::cout << "menu draw" << std::endl;
}