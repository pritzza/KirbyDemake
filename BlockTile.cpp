#include "BlockTile.h"

BlockTile::BlockTile(float x, float y, float t) : Tile (x, y, t) // i dont know the syntax to do this
{
	collisionType = 1;

	color = sf::Color::Green;
	shape.setFillColor(color);
}