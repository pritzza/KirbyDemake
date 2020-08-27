#include "Tile.h"

Tile::Tile(float x, float y, float gridSizef)
{
	shape.setSize(sf::Vector2f(gridSizef, gridSizef));
	shape.setFillColor(sf::Color::Green);
	shape.setOutlineThickness(2);
	shape.setPosition(x, y);
}

Tile::~Tile()
{

}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(shape);
}