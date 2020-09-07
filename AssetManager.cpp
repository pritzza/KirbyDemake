#include "AssetManager.h"

#include <iostream>

AssetManager::AssetManager() {}

AssetManager::~AssetManager() 
{
	clearAssets();
}

void AssetManager::clearAssets()
{
	for (auto s : textKeys)
		textures.erase(s);
	for (auto s : fontKeys)
		textures.erase(s);
}

void AssetManager::loadTexture(std::string name, std::string fileName)
{
	sf::Texture tex;

	if (tex.loadFromFile(fileName))
	{
		textKeys.push_back(fileName);
		this->textures[name] = tex;
	}
}

sf::Texture* AssetManager::getTexture(std::string name)
{
	try
	{
		return &textures.at(name);
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
		fontKeys.push_back(fileName);
		this->fonts[name] = font;
	}
}

sf::Font* AssetManager::getFont(std::string name)
{
	try
	{
		return &fonts.at(name);
	}
	catch (std::out_of_range& const e)
	{
		std::cerr << e.what() << std::endl;
	}
}