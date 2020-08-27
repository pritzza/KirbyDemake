#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	bool jumpFlag { false };
	bool leftFlag{ false };
	bool rightFlag{ false };
	bool sprintFlag{ false };
	int direction{ 0 };

	const float sprintSpeed{ 2.0f };
	const float walkSpeed{ 1.0f };

public:
	Player(std::vector<Entity*>& entities) : Entity(entities) {  }

	void update();

	void jump();
	void move();
	void toggleSprint();

	void handleInput(char input);
};