#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"

using namespace std;

class Entity
{
public:
	Entity();

	void setTexture(sf::Texture* texture);
	void setPosition(float x, float y);
	void incrementTexture();
	void updateTexture(sf::Texture* texture, TextureManager::AssetType assetType);

	sf::Sprite* getSprite();

private:
	TextureManager::AssetType assetType;
	sf::Texture* texture;
	sf::Sprite* sprite;

	int counter;
};
