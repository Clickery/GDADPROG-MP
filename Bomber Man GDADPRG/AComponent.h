#pragma once
#include <iostream>
#include <string> 
#include <SFML/Graphics.hpp>

using namespace std;
class AGameObject; //aviod circular import, forward declaration/ mas mauuna ito magdraw kesa sa iba

class AComponent
{
public:
	enum ComponentType { NotSet = -1, Script = 0, Renderer = 1, Input = 2 };
	AComponent(string name, ComponentType type);
	~AComponent();

	void attachOwner(AGameObject* owner);
	void detachOwner();
	AGameObject* getOwner();
	ComponentType getType();
	string getName();

	void setDeltaTime(sf::Time deltaTime);
	virtual void perform() = 0; // performs associated action

protected:
	AGameObject* owner;
	ComponentType type;
	string name;
	sf::Time deltaTime;
};

