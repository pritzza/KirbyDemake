#pragma once

#include <vector>

#include "GameState.h"

class GameStateManager
{
public:
	std::vector<GameState*> states;
	GameState* tempAddingState;

	bool isAdding;
	bool isRemoving;
	bool isReplacing;

public:
	GameStateManager();
	~GameStateManager();

	void processStateChange();

	void addState(GameState* state, bool isReplacing);
	void removeState();

	GameState* currentState();
};