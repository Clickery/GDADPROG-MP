#include "GameLoop.h"
#include "ApplicationManager.h"
#include "TextureManager.h"
#include "GameObjectManager.h"
#include "BomberManObject.h"
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "GameScene.h"

using namespace sf;
using namespace std;

const sf::Time GameLoop::TIME_PER_FRAME = sf::seconds(1.f / 60.f);

GameLoop::GameLoop():window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bomber Man")
{
	ApplicationManager::initialize(&this->window);

	TextureManager::getInstance()->loadAll(); // load all textures

	//BomberManObject* bomberMan = new BomberManObject("BomberMan");
	//GameObjectManager::getInstance()->addObject(bomberMan);
	
	

	SceneManager::getInstance()->registerScene(new MainMenuScene());
	SceneManager::getInstance()->registerScene(new GameScene());
	SceneManager::getInstance()->loadScene(SceneManager::MAIN_MENU_SCENE_NAME);
}


void GameLoop::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (this->window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;

			processEvents();
			update(TIME_PER_FRAME);
		}
		render();
	}
}


void GameLoop::processEvents()
{
	sf::Event event;
	if (this->window.pollEvent(event)) {
		switch (event.type) {

		case sf::Event::Closed:
			this->window.close();
			break;

		default:
			GameObjectManager::getInstance()->processInput(event);
			break;
		}
	}
}

void GameLoop::update(sf::Time elapsedTime)
{
	
	if (ApplicationManager::getInstance()->isPaused() == false)
	{
		GameObjectManager::getInstance()->update(elapsedTime);
	}
	
}


void GameLoop::render()
{
	this->window.clear();
	GameObjectManager::getInstance()->draw(&this->window);
	this->window.display();
}
