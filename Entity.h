#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

class TileMap;
class AssetManager;

class Entity
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;

	int width;
	int height;

	float xPos;
	float yPos;

	float xVel;
	float yVel;

	float xAcc;
	float yAcc;

	float velocityMax;
	float velocityMin;
	float drag;

	bool grounded;

public:
	Entity(std::vector<Entity*>& entities);
	~Entity();

	virtual void init(AssetManager* assets);

	virtual void initSprite(AssetManager* assets);
	virtual void initPhysics();
	//void inittexture, sprite, animations, variables

	virtual void update(TileMap* t, sf::Text& debugText); //will need dt and world ptr to interact with tiles and other enemys and stuff

	void updatePhysics();
	void updatePosition(TileMap* t, sf::Text& debugText);
	void updateSprite();
	//void updateAnimation();

	sf::Vector2i getCollisionPoint(int corner, bool isNext);
	virtual int isColliding(TileMap* t, sf::Vector2i current, sf::Vector2i next, int corner);
	void collide();
};