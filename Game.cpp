#include "Game.h"
#include "GameState.h"

Game::Game(GameState* state)
{
    window.create(sf::VideoMode(800, 600), "Window");

    window.setFramerateLimit(5);

    pushState(state);
}

Game::~Game()
{
    while (!states.empty())
        popState();
}

void Game::popState()
{
    std::cout << states.size();
    if (!states.empty())
    {
        delete states.back();
        states.pop_back();
    }
    std::cout << states.size();
}

void Game::pushState(GameState* state)
{
    states.push_back(state);
}

GameState* Game::currentState()
{
    if (states.empty())
    {
        std::cout << "currentState() returned nullptr\n";
        return nullptr;
    }
    else
        return states.back();
}

void Game::gameLoop()
{
    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asMilliseconds();

        // exception handling
        if (currentState() == nullptr)
            continue;

        currentState()->handleInput();

        currentState()->update();

        // clear the window with black color
        window.clear(sf::Color::Black);

        currentState()->draw();

        // end the current frame
        window.display();

        std::cout << "gameloop\n";
    }
}