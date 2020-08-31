#pragma once
 
#include "Tile.h"
#include <SFML/System.hpp>


class TileMap
{
public:
    int layers;
    float gridSizeF = 50.0f;
    unsigned gridSizeU;
    sf::Vector2u maxSize;
    std::vector< std::vector < std::vector <Tile*> > > map;

public:
    TileMap(unsigned width, unsigned height, int level);
    ~TileMap();

    void clear();

    void update();
    void render(sf::RenderTarget& target);


    Tile* getTileMap(int x, int y, int level);
    Tile* getTile(int x, int y, char id);
};