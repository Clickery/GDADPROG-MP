#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include "AGameObject.h"

using namespace std;

class BomberManObject : public AGameObject
{
public:
	BomberManObject(string name);
	~BomberManObject();
	void initialize();

private:
	bool isAlive = true;
	
};

