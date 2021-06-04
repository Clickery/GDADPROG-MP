#include "MainMenuScreen.h"
#include "TextureManager.h"
#include "GameLoop.h"
#include "UIButton.h"
#include <iostream>
#include "UIText.h"
//#include "SamplePopupScreen.h"
#include "GameObjectManager.h"
//#include "QuitScreen.h"
#include "SceneManager.h"

MainMenuScreen::MainMenuScreen(string name) :AView(name), ButtonListener()
{
}

MainMenuScreen::~MainMenuScreen()
{
	AView::~AView();
}

void MainMenuScreen::initialize()
{
	this->entity = new Entity;
	this->entity->updateTexture(TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::MAIN_MENU_BG, 0), TextureManager::AssetType::MAIN_MENU_BG);
	sf::Vector2u textureSize = this->entity->getSprite()->getTexture()->getSize();
	float xScale = (float)GameLoop::WINDOW_WIDTH / (float)textureSize.x;
	float yScale = (float)GameLoop::WINDOW_HEIGHT / (float)textureSize.y;
	this->entity->getSprite()->scale(xScale, yScale);
	this->entity->getSprite()->setPosition(GameLoop::WINDOW_WIDTH / 2, GameLoop::WINDOW_HEIGHT / 2);


	sf::Texture* normalTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonNormal, 0);
	sf::Texture* pressedTexture = TextureManager::getInstance()->getTextureAt(TextureManager::AssetType::ButtonPressed, 0);

	UIButton* button = new UIButton(normalTexture, pressedTexture, "main_menu_button_1");
	this->attachChild(button);
	button->getEntity()->getSprite()->setPosition(textureSize.x / 2, textureSize.y / 2 + 100);
	button->getEntity()->getSprite()->setScale(0.2f, 0.2f);
	button->setButtonListener(this);

}

void MainMenuScreen::onButtonClick(UIButton* button)
{

}

void MainMenuScreen::onButtonReleased(UIButton* button)
{
	if (button->getName() == "main_menu_button_1") {

		cout << "Play!!!\n";
		SceneManager::getInstance()->loadScene(SceneManager::GAME_SCENE_NAME_1);
	}
	
}
