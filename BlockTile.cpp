#include "BlockTile.h"

BlockTile::BlockTile(float x, float y) : Tile (x, y) // i dont know the syntax to do this
{
	color = sf::Color::Green;
	isSolid = true;
	shape.setFillColor(color);
}