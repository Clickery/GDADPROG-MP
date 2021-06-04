#pragma once
#include "AComponent.h"
#include <iostream>
class BomberManMovement : public AComponent
{

public:
	BomberManMovement(string name);
	~BomberManMovement();
	void perform();

private:
	const float SPEED_MULTIPLIER = 300.0f;
	


};

