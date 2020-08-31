#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.h"

class TileMap;

class Entity
{
public:
	sf::RectangleShape rect;

	int width{ 25 };
	int height{ 50 };

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

	virtual void update(TileMap* t); //will need dt and world ptr to interact with tiles and other enemys and stuff

	void updatePhysics();
	void updatePosition(TileMap* t);
	//void updateAnimation();
	void updateSprite();

	virtual int isColliding(TileMap* t);
	void collide();

	void initPhysics();
	//void inittexture, sprite, animations, variables

};