#include "Tile.h"

Tile::Tile(float x, float y)
{
	init(x, y);
}

Tile::~Tile()
{
	//delete this;
}

void Tile::init(float x, float y)
{
	shape.setSize(sf::Vector2f(length, length));
	shape.setOutlineThickness(2);
	shape.setPosition(x * length, y * length);

	shape.setFillColor(sf::Color::Black);
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(shape);
}