#include "Player.h"

#include "Constants.h"
#include <iostream>

//Player::Player(std::vector<Entity*>& entities) : Entity (entities)
//{
//	
//}

Player::~Player()
{

}

void Player::init(AssetManager* assets)
{
	initSprite(assets);
	initPhysics();
}

void Player::jump()
{

}

void Player::update(TileMap* t, sf::Text& debugText)
{
	move();

	updatePhysics();
	updatePosition(t, debugText);
	updateSprite();
}

void Player::move()
{
	if (rightFlag)	// move right
		xVel += 1.0f * xAcc;
	if (leftFlag)	// move left
		xVel -= 1.0f * xAcc;
	if (jumpFlag && jumpFrameIndex < maxJumpFrames)	// jump
	{
		yVel = -(yAcc + GRAVITY_FORCE);
		++jumpFrameIndex;
	}
	
	//std::cout << jumpFrameIndex;
}

void Player::toggleSprint()
{
	if (sprintFlag)
	{
		xAcc = sprintSpeed;
	}
	else
	{
		xAcc = walkSpeed;
	}
}

void Player::handleInput(char input)
{
	switch (input)
	{
	case ('L'):
		leftFlag = true;
		break;
	case ('l'):
		leftFlag = false;
		break;
	case ('R'):
		rightFlag = true;
		break;
	case ('r'):
		rightFlag = false;
		break;
	case ('J'):
		jumpFlag = true;
		break;
	case ('j'):
		jumpFlag = false;
		jumpFrameIndex = 0;
		break;
	case('S'):
		sprintFlag = true;
		toggleSprint();
		break;
	case ('s'):
		sprintFlag = false;
		toggleSprint();
		break;
	}

	//std::cout << "\n\nleftFlag:" << leftFlag << std::endl;
	//std::cout << "rightFlag:" << rightFlag << std::endl;
}