#include "AirTile.h"

AirTile::AirTile(float x, float y) : Tile(x, y) // i dont know the syntax to do this
{
	color = sf::Color::Cyan;
	isSolid = false;
	shape.setFillColor(color);
}