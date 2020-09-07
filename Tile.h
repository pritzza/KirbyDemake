#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Tile
{
public:
	sf::RectangleShape shape;
	sf::Color color{ sf::Color::Black }; // for collision debugging

	float length;
	int collisionType;	// So far I think well have 3 collision types, where 1 is nonsolid, 2 is solid, and 3 kills you on contact

public:
	Tile(float x, float y, float l);
	~Tile();

	virtual void init(float x, float y, float l);

	void update();
	void render(sf::RenderTarget& target);

	//virtual void bottomCollide();
	//virual void hit();
};