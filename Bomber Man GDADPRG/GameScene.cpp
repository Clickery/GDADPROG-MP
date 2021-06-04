#include "GameScene.h"
#include "GameObjectManager.h"
#include <iostream>
#include "BomberManObject.h"
#include "TileMap.h"
GameScene::GameScene() : AScene("GameScene")
{

}

GameScene::~GameScene()
{

}

void GameScene::onLoadResources()
{
}

void GameScene::onLoadObjects()
{
	cout << "GameScene!!!\n";
	TileMap* tileMap = new TileMap();
	tileMap->initialize();
	BomberManObject* bomberMan = new BomberManObject("BomberMan");
	GameObjectManager::getInstance()->addObject(bomberMan);
	

}

void GameScene::onUnloadResources()
{

}
