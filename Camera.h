#pragma once

#include <SFML/System.hpp>

class Camera
{
public:
	sf::Vector2i position;

public:
	Camera();
	~Camera();

	void update();
};