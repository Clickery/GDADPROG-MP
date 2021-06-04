#include "BomberManAnimation.h"
#include "PlayerInputController.h"
#include "AGameObject.h"
#include "GameLoop.h"
BomberManAnimation::BomberManAnimation(string name) : AComponent(name, Script)
{
}

BomberManAnimation::~BomberManAnimation()
{
	AComponent::~AComponent();
}

void BomberManAnimation::perform()
{
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	sf::Sprite* playerSprite = this->getOwner()->getEntity()->getSprite();

	

	if (playerSprite == NULL || inputController == NULL) {
		std::cout << "One or more of the needed dependencies are missing!" << endl;
		return;
	}

	
	if (inputController->isUp()) {
		this->getOwner()->getEntity()->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::BomberManBack, 0), TextureManager::AssetType::BomberManBack);
		this->getOwner()->getEntity()->incrementTexture();
	}

	else if (inputController->isDown()) {
		
		this->getOwner()->getEntity()->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::BomberManFront , 0), TextureManager::AssetType::BomberManFront);
		this->getOwner()->getEntity()->incrementTexture();
	}

	else if (inputController->isRight()) {
		
		this->getOwner()->getEntity()->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::BomberManRight, 0), TextureManager::AssetType::BomberManRight);
		this->getOwner()->getEntity()->incrementTexture();
	}

	else if (inputController->isLeft()) {

		this->getOwner()->getEntity()->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::BomberManLeft, 0), TextureManager::AssetType::BomberManLeft);	
		this->getOwner()->getEntity()->incrementTexture();
	}

	



	
	
}
