#include "BomberManMovement.h"
#include "PlayerInputController.h"
#include "AGameObject.h"


BomberManMovement::BomberManMovement(string name) : AComponent(name, Script)
{
	
}

BomberManMovement::~BomberManMovement()
{
	AComponent::~AComponent();
}

void BomberManMovement::perform()
{
	PlayerInputController* inputController = (PlayerInputController*)this->getOwner()->getComponentsOfType(ComponentType::Input)[0];
	sf::Sprite* playerSprite = this->getOwner()->getEntity()->getSprite();

	if (playerSprite == NULL || inputController == NULL) {
		std::cout << "One or more of the needed dependencies are missing!" << endl;
		return;
	}

	sf::Vector2f offset(0.0f, 0.0f);

	if (inputController->isUp()) {
		offset.y -= this->SPEED_MULTIPLIER;
		playerSprite->move(offset * deltaTime.asSeconds());
	}

	else if (inputController->isDown()) {
		offset.y += this->SPEED_MULTIPLIER;
		playerSprite->move(offset * deltaTime.asSeconds());
	}

	else if (inputController->isRight()) {
		offset.x += this->SPEED_MULTIPLIER;
		playerSprite->move(offset * deltaTime.asSeconds());
	}

	else if (inputController->isLeft()) {
		offset.x -= this->SPEED_MULTIPLIER;
		playerSprite->move(offset * deltaTime.asSeconds());
	}
}
