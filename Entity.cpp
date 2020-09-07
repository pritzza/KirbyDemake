#include "Entity.h"

#include <iostream>
#include <string>

#include "Constants.h"
#include "TileMap.h"
#include "AssetManager.h"

Entity::Entity(std::vector<Entity*>& entities)
{
	entities.push_back(this);
}

Entity::~Entity()
{

}

void Entity::init(AssetManager* assets)
{
	initSprite(assets);
	initPhysics();
}

void Entity::initSprite(AssetManager* assets)
{
	width = 25;
	height = 49;

	rect.setSize(sf::Vector2f(width, height));
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(1);
	rect.setPosition(xPos, yPos);
}

void Entity::initPhysics()
{
	xPos = WINDOW_WIDTH / 2;
	yPos = WINDOW_HEIGHT / 2;

	xVel = 0;
	yVel = 0;
	xAcc = 1.f;
	yAcc = 10.0f;
	velocityMax = 9.8f;
	velocityMin = 0.1f;
	drag = 0.99f;

	grounded = false;
}

void Entity::update(TileMap* t, sf::Text& debugText) //will need dt and world ptr to interact with tiles and other enemys and stuff
{
	updatePhysics();
	updatePosition(t, debugText);
	updateSprite();
}

void Entity::updatePhysics()
{
	if (!grounded)
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

	// Limit acceleration
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

void Entity::updatePosition(TileMap* t, sf::Text& debugText)
{
	int collisionCase[4];

	for (int i = 0; i < 4; ++i)
	{
		sf::Vector2i pointCurrent = getCollisionPoint(i, false);
		sf::Vector2i pointNext = getCollisionPoint(i, true);

		if (i == 0 || i == 1)
			std::cout << "current: " << pointCurrent.y << " next: " << pointNext.y << std::endl;

		//std::cout << "current(" << pointCurrent.x << ", " << pointCurrent.y << ")\nnext(" << pointNext.x << ", " << pointNext.y << ")\n\n";

		collisionCase[i] = isColliding(t, pointCurrent, pointNext, i);	// isCollising() is actuall dealing with all collisions rn
	}

	for (int i = 0; i < 4; ++i)
	{
		switch (collisionCase[i])
		{
		case (0):	// no collision
			break;
		case (1):	// vertical solid collision
			if (yVel < 0)
				yPos = (static_cast<int>(yPos / t->gridSizeF) * t->gridSizeF);
			//else if (yVel > 0)
			//	yPos = (static_cast<int>(yPos / t->gridSizeF) * t->gridSizeF) + (t->gridSizeF - height);
			yVel = 0;
			break;
		case (2):	// horizontal solid collision
			xVel = 0;
			break;
		case (3):	// h and v solid collision

			// need to come up with a system better than this
			//if (yVel < 0)
			//	yPos = (static_cast<int>((yPos + 50) / t->gridSizeF) * t->gridSizeF);
			//if (yVel > 0)
			//	yPos = (static_cast<int>(((yPos) / t->gridSizeF) * t->gridSizeF));
			//if (xVel < 0)
			//	xPos = (static_cast<int>((xPos + 50) / t->gridSizeF) * t->gridSizeF);
			//if (xVel > 0)
			//	xPos = (static_cast<int>(((xPos) / t->gridSizeF) * t->gridSizeF));
			xVel = 0;
			yVel = 0;
			break;
		case (4):	// death collision
			break;
		}
	}

	xPos += xVel;
	yPos += yVel;

	// Simple text for debug info
	std::string cordText{ "xPos: " + std::to_string(xPos) + '\n' +
						"yPos: " + std::to_string(yPos) + '\n' +
						"xVel: " + std::to_string(xVel) + '\n' +
						"yVel: " + std::to_string(yVel) + '\n' };

	debugText.setString(cordText);

	//std::cout << "(x, y): (" << xPos << ", " << yPos << ")   (xVel, yVel): (" << xVel << ", " << yVel << ")\n";
}

void Entity::updateSprite()
{
	rect.setPosition(xPos, yPos);
}

sf::Vector2i Entity::getCollisionPoint(int corner, bool isNext)
{
	// corner order goes: TOPLEFT, TOPRIGHT, BOTTOMLEFT, BOTTOMRIGHT

	// start with xPos, add width if even, add vel if this is next point, then divide by gridsize
	int x = static_cast<int> ((xPos + (width * (corner % 2)) + (isNext * xVel)) / gridSize);
	// start with yPos, add height if in second half of 4 corners, add vel if this is next point, then divide by gridsize
	int y = static_cast<int> ((yPos + (height * (corner / 2)) + (isNext * yVel)) / gridSize);

	//std::cout << "y:: " << y << " actual: " << (yPos + (height * (corner / 2)) + (isNext * yVel)) / gridSize << std::endl;

	return sf::Vector2i{ x, y };
}

int Entity::isColliding(TileMap* t, sf::Vector2i current, sf::Vector2i next, int corner)
{
	if (!corner)
	{
		for (auto& x : t->map)
			for (auto& y : x)
				for (auto& z : y)
					z->shape.setFillColor(z->color);
	}

	int returnValue{ 0 };

	// if inside map bounds
	if (next.x >= 0 && next.x < t->map.size())
	{
		if (next.y >= 0 && next.y < t->map[0].size())
		{
			// This is what makes tiles change color after collision
			//if(t->map[next.x][next.y][0]->collisionType == 1)
			t->map[current.x][current.y][0]->shape.setFillColor(sf::Color::Blue);
			t->map[next.x][next.y][0]->shape.setFillColor(sf::Color::Red);

			if (t->map[current.x][next.y][0]->collisionType)	// if you set this to [nextX][nextY], you can get wall jumps
			{
				returnValue += 1;	// vertical collision
			}
			if (t->map[next.x][current.y][0]->collisionType)
				returnValue += 2;	// horizontal collision
		}
		else
			returnValue += 1;
	}
	else
		returnValue += 2;

	return returnValue;	// 0 means no collision, 3 means vertical and horizontal collision
}

void Entity::collide()
{

}