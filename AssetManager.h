#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void loadTexture(std::string name, std::string fileName);
	sf::Texture getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font getFont(std::string name);

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;

};