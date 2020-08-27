#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class Entity
{
public:
	sf::RectangleShape rect;

	int width{ 33 };
	int height{ 66 };

	float xPos{ WINDOW_WIDTH / 2 };
	float yPos{ WINDOW_HEIGHT / 2 };

	float xVel{ 0 };
	float yVel{ 0 };
	float xAcc{ 1.0f };
	float yAcc{ 10.0f };

	float velocityMax{ 9.8f };
	float velocityMin{ 0.1f };
	float drag{ 0.99f };

public:
	Entity(std::vector<Entity*>& entities);

	virtual void update(); //will need dt and world ptr to interact with tiles and other enemys and stuff

	void updatePhysics();
	//void updateAnimation();
	void updateSprite();

	bool isColliding();
	void collide();

	void initPhysics();
	//void inittexture, sprite, animations, variables

};