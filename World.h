#pragma once

#include "TileMap.h"
#include "Camera.h"

class World
{
public:
	TileMap t{16, 12, 0};
	Camera c;

public:
	World();
};