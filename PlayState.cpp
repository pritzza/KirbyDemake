#include "PlayState.h"
#include "MenuState.h"
#include "GameStateManager.h"
#include <iostream>

void PlayState::handleInput()
{
	std::cout << "play input" << std::endl;
}
void PlayState::update() 
{
	std::cout << "play update" << std::endl;
}
void PlayState::draw() 
{
	std::cout << "play draw" << std::endl;
	std::cout << "play calling addState" << std::endl;

	stateMachine->addState(new MenuState(stateMachine, window), true);
}