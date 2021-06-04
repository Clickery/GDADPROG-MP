#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include "AComponent.h"
#include "Entity.h"



using namespace std;
using namespace sf;

class AGameObject : sf::NonCopyable
{
public:
	AGameObject(string name);
	~AGameObject();
	virtual void initialize() = 0;
	virtual void draw(sf::RenderWindow* window, sf::RenderStates renderStates);
	string getName();
	Entity* getEntity();

	void attachChild(AGameObject* child);
	void detachChild(AGameObject* child);
	void setPos(float x, float y);

	sf::FloatRect getLocalBounds();
	sf::FloatRect getWorldBounds();
	AGameObject* getParent();

	typedef vector <AGameObject*> ObjectList;
	typedef vector <AComponent*> ComponentList;

	ObjectList getChildren();
	void updateChildren(ObjectList objectList, sf::Time deltaTime);

	void attachComponent(AComponent* component);
	void detachComponent(AComponent* component);

	AComponent* findComponentByName(string name);
	AComponent* findComponentOfType(AComponent::ComponentType type, string name);
	ComponentList getComponentsOfType(AComponent::ComponentType type);
	ComponentList getComponentsOfTypeRecursive(AComponent::ComponentType type);


protected:
	string name;
	//sf::Sprite* sprite;
	//sf::Texture* texture;
	Entity* entity;
	ObjectList childList; // this allows parenting of game object
	ComponentList componentList;

	AGameObject* parent = nullptr;

private:
	ComponentList getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, ComponentList foundList);
};

