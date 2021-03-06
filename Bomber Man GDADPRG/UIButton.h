#pragma once
#include "AGameObject.h"
#include "TextureManager.h"
#include "UIButtonInputController.h"

class UIButton :public AGameObject
{
public:
	UIButton(sf::Texture* normalTexture, sf::Texture* pressedTexture, string name);
	~UIButton();

	void initialize();
	void setButtonListener(ButtonListener* listener);
	void changeButtontoNormal();
	void changeButtonToPressed();


private:
	sf::Texture* normalTexture = NULL;
	sf::Texture* pressedTexture = NULL;
	ButtonListener* listener;
};

