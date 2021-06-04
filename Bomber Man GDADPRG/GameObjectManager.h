#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <string>
#include "AGameObject.h"
//#include "GenericInputController.h"

using namespace std;
using namespace sf;

typedef unordered_map<string, AGameObject*> HashTable;
typedef vector<AGameObject*> List;

// Singleton class
// Manages Game Objects
class GameObjectManager
{
public:
	static GameObjectManager* getInstance();
	AGameObject* findObjectByName(string name);
	List getAllObjects();
	int activeObjects();
	void processInput(sf::Event event);
	void processInputChildren(AGameObject::ObjectList objectList, sf::Event event);
	void update(sf::Time deltaTime);
	void updateChildren(AGameObject::ObjectList objectList, sf::Time deltaTime);
	void draw(sf::RenderWindow* window);
	void addObject(AGameObject* gameObject);
	void deleteObject(AGameObject* gameObject);
	void deleteObjectByName(string name);
	void deleteAllObjectsInScene();

private:
	GameObjectManager() { };
	GameObjectManager(GameObjectManager const&) { };
	GameObjectManager& operator = (GameObjectManager const&) { };
	static GameObjectManager* sharedInstance;

	HashTable gameObjectMap;
	List gameObjectList;
};

