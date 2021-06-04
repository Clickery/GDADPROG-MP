#include "TileObject.h"

TileObject::TileObject(string name, TileType tileType, Vector2i coords) : AGameObject(name)
{
	this->tileType = tileType;
	this->coords = coords;
}

TileObject::~TileObject()
{
}

TileObject::TileType TileObject::GetTileType()
{
	return this->tileType;
}

Vector2i TileObject::GetCoords()
{
	return this->coords;
}

void TileObject::initialize()
{

	std::cout << "Declared as " << this->getName() << endl;

	this->entity = new Entity;

	if(this->tileType == TileType::Block)
		this->entity->setTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::SolidBlock, 0));
	else if(this->tileType == TileType::Walkable)
		this->entity->setTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::WalkableGround, 0));
	else if (this->tileType == TileType::Destructible)
		this->entity->setTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ExpodableBlock, 0));
	else if (this->tileType == TileType::Portal)
		this->entity->setTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::Portal, 0));


	sf::Vector2u textureSize = this->entity->getSprite()->getTexture()->getSize();
	this->entity->getSprite()->setPosition(textureSize.x * (this->coords.x) + 32, textureSize.y * (this->coords.y) + 32);
}
