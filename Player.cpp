#include "Player.h"

#include "Constants.h"
#include <iostream>

//Player::Player(std::vector<Entity*>& entities) : Entity (entities)
//{
//	//std::cout << "player constrcutor";
//}

void Player::jump()
{
	//if (jumpFlag)
	//{
	//	yVel = -100;
	//}
}

void Player::update()
{
	move();

	updatePhysics();
	updateSprite();
}

void Player::move()
{
	if (rightFlag)
		xVel += 1.0f * xAcc;
	if (leftFlag)
		xVel -= 1.0f * xAcc;
	if (jumpFlag)
		yVel = -(yAcc + GRAVITY_FORCE);
	
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