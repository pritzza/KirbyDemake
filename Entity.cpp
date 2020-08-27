#include "Entity.h"

#include <iostream>

Entity::Entity(std::vector<Entity*>& entities)
{
	rect.setSize(sf::Vector2f(width, height));
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(1);
	rect.setPosition(xPos, yPos);

	entities.push_back(this);
}

void Entity::update() //will need dt and world ptr to interact with tiles and other enemys and stuff
{
	updatePhysics();
	updateSprite();
}

void Entity::initPhysics()
{
	//velocityMax = 10.0f;
	//velocityMin = 0.90f;
	//acceleration = 12.0f;
	//drag = 0.1f;
}

void Entity::updatePhysics()
{

	yVel += GRAVITY_FORCE;

	// Deceleration
	if (xVel)
		xVel *= (drag - 0.15f);
	if (yVel)
		yVel *= drag;

	if (isColliding())
	{
		collide();
	}

	// Limit deceleration
	if (xVel < velocityMin && xVel > -velocityMin)
		xVel = 0;
	if (yVel < velocityMin && yVel > -velocityMin)
		yVel = 0;

	if (xVel > velocityMax || xVel < -velocityMax)
		if (xVel > 0)
			xVel = velocityMax;
		else if (xVel < 0)
			xVel = -velocityMax;

	if (yVel > velocityMax || yVel < -velocityMax)
		if (yVel > 0)
			yVel = velocityMax;
		else if (yVel < 0)
			yVel = -velocityMax;


	xPos += xVel;
	yPos += yVel;

	std::cout << "(x, y): (" << xPos << ", " << yPos << ")   (xVel, yVel): (" << xVel << ", " << yVel << ")\n";

}

void Entity::updateSprite()
{
	rect.setPosition(xPos, yPos);
}

bool Entity::isColliding()
{
	if (yPos > 500)
		return true;

	return false;
}

void Entity::collide()
{
	if (yVel > 0)
		yVel = 0;
}