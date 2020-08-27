#include "AssetManager.h"

#include <iostream>

AssetManager::AssetManager() {}

AssetManager::~AssetManager() {}

void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		this->textures[name] = tex;
	}
}

sf::Texture AssetManager::getTexture(std::string name)
{
	try
	{
		return textures.at(name);
	}
	catch (std::out_of_range& const e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void AssetManager::loadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->fonts[name] = font;
	}
}

sf::Font AssetManager::getFont(std::string name)
{
	try
	{
		return fonts.at(name);
	}
	catch (std::out_of_range& const e)
	{
		std::cerr << e.what() << std::endl;
	}
}