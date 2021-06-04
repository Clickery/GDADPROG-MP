#include "Entity.h"

Entity::Entity()
{
	this->texture = new sf::Texture();
	this->sprite = new sf::Sprite();
}

void Entity::setTexture(sf::Texture* texture)
{
	sf::Vector2u* size;
	this->texture = texture;
	this->sprite->setTexture(*texture);
	size = new sf::Vector2u;
	*size = this->texture->getSize();
	this->sprite->setOrigin(size->x / 2, size->y / 2);
}

void Entity::setPosition(float x, float y)
{
	this->sprite->setPosition(x, y);
}

void Entity::incrementTexture()
{
	int size = TextureManager::getInstance()->getTextureLength(this->assetType);

	this->counter = (this->counter + 1) % size;

	sf::Texture* texture = TextureManager::getInstance()->getTextureAt(this->assetType, this->counter);
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}

void Entity::updateTexture(sf::Texture* texture, TextureManager::AssetType assetType)
{
	this->assetType = assetType;
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
	sf::Vector2u textureSize = this->texture->getSize();
	this->sprite->setOrigin(textureSize.x / 2, textureSize.y / 2);
}

sf::Sprite* Entity::getSprite()
{
	return this->sprite;
}