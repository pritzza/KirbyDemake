#include "MenuState.h"
#include "PlayState.h"
#include "GameStateManager.h"
#include <iostream>



void MenuState::handleInput()
{
	std::cout << "menu input" << std::endl;
}
void MenuState::update()
{
	std::cout << "menu update" << std::endl;
}
void MenuState::draw()
{
	std::cout << "menu draw" << std::endl;
	std::cout << "menu calling addState" << std::endl;

	stateMachine->addState(new PlayState(stateMachine, window), true);
}