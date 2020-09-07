#include "PlayState.h"
#include "MenuState.h"

#include "GameData.h"

#include <iostream>

PlayState::PlayState(GameData* data, sf::RenderWindow* window) : GameState(data, window)
{
	init();
}

PlayState::~PlayState()
{
	data->assets.clearAssets();

	while (!entities.empty())
		entities.pop_back();
}

void PlayState::init()
{
	for (auto& e : entities)
		e->init(&data->assets);

	initDebugText();
}

void PlayState::terminate()
{

}

void PlayState::initDebugText()
{
	data->assets.loadFont("f", "res/bahnschrift.ttf");

	debugText.setFont(*data->assets.getFont("f"));

	debugText.setCharacterSize(24);
	debugText.setFillColor(sf::Color::Black);
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
		e->update(&w.t, debugText);

	//std::cout << "play update" << std::endl;
	//std::cout << "PLAY STATE HAS: " << entities.size() << "ENTITIES";
}
void PlayState::draw()
{
	w.t.render(*window, sf::Vector2i(static_cast<int>((p.xPos + p.width / 2) / w.t.gridSizeF), static_cast<int>((p.yPos + p.height / 2) / w.t.gridSizeF)));

	for (Entity* e : entities)
		window->draw(e->rect);

	window->draw(debugText);

	//std::cout << "play draw" << std::endl;
}