#include "PlayState.h"
#include "MenuState.h"

#include "GameData.h"

#include <iostream>

PlayState::PlayState(GameData* data, sf::RenderWindow* window) : GameState(data, window)
{

}

PlayState::~PlayState()
{
	std::cout << "DECONSTRUCTOR BENIG CALLED";

	while (!entities.empty())
		entities.pop_back();
}

void PlayState::init()
{

}

void PlayState::terminate()
{

}

void PlayState::handleInput()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case (sf::Event::Closed): window->close(); break; break;


		case (sf::Event::KeyReleased):  // If a key is released
		{
			switch (event.key.code)
			{
				// if any movement key is released, stop
			case (sf::Keyboard::A): p.handleInput('l'); break;
			case (sf::Keyboard::D): p.handleInput('r'); break;
			case (sf::Keyboard::Space): p.handleInput('j'); break;
			case (sf::Keyboard::LShift): p.handleInput('s'); break;
			}
		}
		break;


		case (sf::Event::KeyPressed):
		{
			switch (event.key.code)
			{
			case (sf::Keyboard::E):
				//std::cout << "play calling addState type menu" << std::endl;
				data->stateMachine.addState(new MenuState(data, window), true);
				break;

			case (sf::Keyboard::W): p.jump(); break;
			case (sf::Keyboard::A): p.handleInput('L'); break;
			case (sf::Keyboard::D): p.handleInput('R'); break;
			case (sf::Keyboard::Space): p.handleInput('J'); break;
			case (sf::Keyboard::LShift): p.handleInput('S'); break;
			}
		}
		break;


		}
	}
}
//std::cout << "play input" << std::endl;

void PlayState::update()
{
	for (Entity* e : entities)
		e->update(&w.t);

	//std::cout << "play update" << std::endl;
	//std::cout << "PLAY STATE HAS: " << entities.size() << "ENTITIES";
}
void PlayState::draw()
{
	w.t.render(*window);

	for (Entity* e : entities)
		window->draw(e->rect);

	//std::cout << "play draw" << std::endl;
}