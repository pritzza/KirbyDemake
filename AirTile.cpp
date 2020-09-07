#include "AirTile.h"

AirTile::AirTile(float x, float y, float t) : Tile(x, y, t) // i dont know the syntax to do this
{
	collisionType = 0;

	color = sf::Color::Cyan;
	shape.setFillColor(color);
}