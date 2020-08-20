#include "PlayState.h"
#include "MenuState.h"

PlayState::PlayState(Game* game)
{
	this->game = game;
}

void PlayState::draw()
{
	std::cout << "playState draw\n";
}
void PlayState::update()
{
	std::cout << "playState update\n";
}
void PlayState::handleInput()
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
                quitGame();
            break;

        }
    }

	std::cout << "playState handleinput\n";
}

void PlayState::quitGame()
{
	game->popState();
	game->pushState(new MenuState(game));
}