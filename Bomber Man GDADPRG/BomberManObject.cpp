#include "BomberManObject.h"
#include <iostream>
#include "TextureManager.h"
#include <SFML/Graphics.hpp>
#include "PlayerInputController.h"
#include "BomberManMovement.h"
#include "Entity.h"
#include "BomberManAnimation.h"

BomberManObject::BomberManObject(string name) : AGameObject(name) {

}

BomberManObject::~BomberManObject()
{
	AGameObject::~AGameObject();
}

void BomberManObject::initialize() {
	std::cout << "Declared as " << this->getName() << endl;

	this->entity = new Entity;
	this->entity->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::BomberManBack, 0), TextureManager::AssetType::BomberManBack);
	sf::Vector2u textureSize = this->entity->getSprite()->getTexture()->getSize();
	this->entity->getSprite()->setPosition(2 * 64 - 32, 2 * 64 -32);


	PlayerInputController* inputController = new PlayerInputController("PlayerInput");
	this->attachComponent(inputController);

	BomberManMovement* movement = new BomberManMovement("BomberManMovement");
	this->attachComponent(movement);

	BomberManAnimation* animation = new BomberManAnimation("BomberManAnimation");
	this->attachComponent(animation);

}

