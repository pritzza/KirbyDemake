#include "MenuState.h"
#include "PlayState.h"

MenuState::MenuState(Game* game)
{
	this->game = game;

    shape.setRadius(150);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(5);
    shape.setPosition(10, 20);
}

void MenuState::draw()
{
    game->window.draw(shape);

	std::cout << "MenuState draw\n";
}
void MenuState::update()
{
	std::cout << "MenuState update\n";
}
void MenuState::handleInput()
{
    sf::Event event;

    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
            /* Close the window */
        case sf::Event::Closed:
            this->game->window.close();
            break;

            //pause game
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space)
                startGame();
            break;

        }
    }

	std::cout << "MenuState handleinput\n";
}

void MenuState::startGame()
{
    game->popState();
    game->pushState(new PlayState(game));
}