#pragma once
#include "AScene.h"
class GameScene : public AScene
{
public:
	GameScene();
	~GameScene();

	void onLoadResources();
	void onLoadObjects();

	void onUnloadResources();
};

