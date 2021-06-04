#include "UIButton.h"

UIButton::UIButton(sf::Texture* normalTexture, sf::Texture* pressedTexture, string name) :AGameObject(name)
{
	this->normalTexture = normalTexture;
	this->pressedTexture = pressedTexture;
}

UIButton::~UIButton()
{
	delete this->listener;
	AGameObject::~AGameObject();
}

void UIButton::initialize()
{
	this->entity = new Entity;
	this->entity->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonNormal, 0), TextureManager::ButtonNormal);
	sf::Vector2u textureSize = this->entity->getSprite()->getTexture()->getSize();
	this->entity->getSprite()->setOrigin(textureSize.x / 2, textureSize.y / 2);
}

void UIButton::setButtonListener(ButtonListener* listener)
{
	this->listener = listener;
	UIButtonInputController* inputController = new UIButtonInputController("UI_InputController", this->listener);
	this->attachComponent(inputController);
}

void UIButton::changeButtontoNormal()
{
	this->entity->getSprite()->setTexture(*this->normalTexture);
}

void UIButton::changeButtonToPressed()
{
	this->entity->getSprite()->setTexture(*this->pressedTexture);
}

