#include "TileMap.h"

TileMap::TileMap(unsigned width, unsigned height)
{
	gridSizeU = static_cast<unsigned>(gridSizeF);
	maxSize.x = width;
	maxSize.y = height;
	layers = 1;

	for (size_t x = 0; x < maxSize.x; ++x)
	{
		map.push_back(std::vector < std::vector<Tile*> >());

		for (size_t y = 0; y < maxSize.y; ++y)
		{
			map[x].push_back(std::vector<Tile*>());
		
			for (size_t z = 0; z < layers; ++z)
			{
				map[x][y].push_back(new Tile(x * gridSizeF, y * gridSizeF ,gridSizeF));
			}
		}
	}

}

TileMap::~TileMap()
{
	for (size_t x = 0; x < maxSize.x; ++x)
	{
		for (size_t y = 0; y < maxSize.y; ++y)
		{
			for (size_t z = 0; z < layers; ++z)
			{
				delete map[x][y][z];
			}
		}
	}
}

void TileMap::update()
{

}

void TileMap::render(sf::RenderTarget& target)
{
	for (auto& x : map)
	{
		for (auto& y : x)
		{
			for (auto& z : y)
			{
				z->render(target);
			}
		}
	}
}