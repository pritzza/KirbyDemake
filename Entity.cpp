#include "Entity.h"

#include "TileMap.h"

#include <iostream>

Entity::Entity(std::vector<Entity*>& entities)
{
	rect.setSize(sf::Vector2f(width, height));
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(1);
	rect.setPosition(xPos, yPos);

	entities.push_back(this);
}

void Entity::update(TileMap* t) //will need dt and world ptr to interact with tiles and other enemys and stuff
{
	updatePhysics();
	updatePosition(t);
	updateSprite();
}

void Entity::updatePosition(TileMap* t)
{
	int collisionCase{ isColliding(t) };	// isCollising() is actuall dealing with all collisions rn

	switch (collisionCase)
	{
	case (0):	// no collision
		break;
	case (1):	// solid collision
		break;
	case (2):	// death collision
		break;
	}
	
	xPos += xVel;
	yPos += yVel;

	std::cout << "(x, y): (" << xPos << ", " << yPos << ")   (xVel, yVel): (" << xVel << ", " << yVel << ")\n";
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

}

void Entity::updateSprite()
{
	rect.setPosition(xPos, yPos);
}

int Entity::isColliding(TileMap* t)
{
	// Currently collision isnt working perfectly because x/y vel values are change as iterating through the 4 collision points
	for (auto& x : t->map)
		for (auto& y : x)
			for (auto& z : y)
				z->shape.setFillColor(z->color);

	// Goes through and checks tile collisions  based off the top left, top right, bottom left, bottom right corners of an entities "hit" box
	for (float collisionPointY = yPos; collisionPointY <= yPos + height; collisionPointY += height)
		for (float collisionPointX = xPos; collisionPointX <= xPos + width; collisionPointX += width)
		{
			//std::cout << "( " << collisionPointX << ", " << collisionPointY << ") ";

			const int currentX = static_cast<int> (collisionPointX / t->gridSizeF);
			const int currentY = static_cast<int> (collisionPointY / t->gridSizeF);
			const int nextX = static_cast<int> ((collisionPointX + xVel) / t->gridSizeF);
			const int nextY = static_cast<int> ((collisionPointY + yVel) / t->gridSizeF);
	
			// if inside map bounds
			if (nextX >= 0 && nextX < t->map.size())
				if (nextY >= 0 && nextY < t->map[0].size())
				{
					// This is what makes tiles change color after collision
					t->map[nextX][nextY][0]->shape.setFillColor(sf::Color::Red);
	
					if (t->map[currentX][nextY][0]->isSolid)	// if you set this to [nextX][nextY], you can get wall jumps
					{
						yVel = 0;
					}
					if (t->map[nextX][currentY][0]->isSolid)
					{
						xVel = 0;
					}
	
				}
		}

	return 0;	// not really utilizing how i wanted collision return values to work rn
}

void Entity::collide()
{
	if (yVel > 0)
		yVel = 0;
}