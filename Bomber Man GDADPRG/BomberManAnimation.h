#pragma once
#include "AComponent.h"
#include <iostream>

class BomberManAnimation : public AComponent
{
public:
	BomberManAnimation(string name);
	~BomberManAnimation();
	void perform();

private:
	const float SPEED_MULTIPLIER = 0.1f;
	float timer;
	bool changeDirection;
};

