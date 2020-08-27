#pragma once
 
#include "Tile.h"
#include <SFML/System.hpp>


class TileMap
{
    int layers;
    float gridSizeF = 50.0f;
    unsigned gridSizeU;
    sf::Vector2u maxSize;
    std::vector< std::vector < std::vector <Tile*> > > map;

public:
    TileMap(unsigned width, unsigned height);
    ~TileMap();

    void update();
    void render(sf::RenderTarget& target);

    void addTile(const float x, const float y);
    void removeTile();
};