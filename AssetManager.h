#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void clearAssets();

	void loadTexture(std::string name, std::string fileName);
	sf::Texture* getTexture(std::string name);

	void loadFont(std::string name, std::string fileName);
	sf::Font* getFont(std::string name);

	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;

	std::vector<std::string> textKeys;
	std::vector<std::string> fontKeys;
};