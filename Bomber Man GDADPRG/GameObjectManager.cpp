#include "GameObjectManager.h"
#include <iostream>
#include "GenericInputController.h" 


GameObjectManager* GameObjectManager::sharedInstance = NULL;

GameObjectManager* GameObjectManager::getInstance() {
	if (sharedInstance == NULL) {
		sharedInstance = new GameObjectManager(); // initialize
	}
	return sharedInstance;
}

AGameObject* GameObjectManager::findObjectByName(string name)
{
	return this->gameObjectMap[name];
}

List GameObjectManager::getAllObjects()
{
	return this->gameObjectList;
}

int GameObjectManager::activeObjects()
{
	return this->gameObjectList.size();
}

void GameObjectManager::processInput(sf::Event event) { // process input
	for (int i = 0; i < this->gameObjectList.size(); i++) { // updated into component 
		AGameObject::ComponentList componentList = this->gameObjectList[i]->getComponentsOfType(AComponent::ComponentType::Input);

		for (int j = 0; j < componentList.size(); j++) {
			// input controller
			GenericInputController* inputController = (GenericInputController*)componentList[j];
			inputController->assignEvents(event);
			inputController->perform();
		}
		this->processInputChildren(this->gameObjectList[i]->getChildren(), event);
	}
}

void GameObjectManager::processInputChildren(AGameObject::ObjectList objectList, sf::Event event)
{
	for (int i = 0; i < objectList.size(); i++) { // updated into component 
		AGameObject::ComponentList componentList = objectList[i]->getComponentsOfType(AComponent::ComponentType::Input);
		for (int j = 0; j < componentList.size(); j++) {
			// input controller
			GenericInputController* inputController = (GenericInputController*)componentList[j];
			
			inputController->assignEvents(event);
			inputController->perform();
		}
		this->processInputChildren(objectList[i]->getChildren(), event);
	}
}

void GameObjectManager::update(sf::Time deltaTime) { // update
	//std::cout << "Delta time: " << deltaTime.asSeconds() << "\n";
	for (int i = 0; i < this->gameObjectList.size(); i++) { // updated into component 
		AGameObject::ComponentList componentList = this->gameObjectList[i]->getComponentsOfType(AComponent::ComponentType::Script);
		
		for (int j = 0; j < componentList.size(); j++) {
			
			componentList[j]->setDeltaTime(deltaTime);
			componentList[j]->perform();
		}
		this->updateChildren(this->gameObjectList[i]->getChildren(), deltaTime);
	}
}

void GameObjectManager::updateChildren(AGameObject::ObjectList objectList, sf::Time deltaTime)
{
	for (int i = 0; i < objectList.size(); i++)
	{
		AGameObject::ComponentList componentList = objectList[i]->getComponentsOfType(AComponent::ComponentType::Script);
		for (int j = 0; j < componentList.size(); j++) {
			componentList[j]->setDeltaTime(deltaTime);
			componentList[j]->perform();
		}
		this->updateChildren(objectList[i]->getChildren(), deltaTime);
	}
}

void GameObjectManager::draw(sf::RenderWindow* window) { // draw to window
	for (int i = 0; i < this->gameObjectList.size(); i++) {
		this->gameObjectList[i]->draw(window, RenderStates::Default);
	}
}

void GameObjectManager::addObject(AGameObject* gameObject) { // add object
	//also initialize the object
	this->gameObjectMap[gameObject->getName()] = gameObject;
	this->gameObjectList.push_back(gameObject);
	this->gameObjectMap[gameObject->getName()]->initialize();
}

//also frees up allocation of the object.
void GameObjectManager::deleteObject(AGameObject* gameObject)
{
	bool isDeleted = false;

	for (int i = 0; i < this->gameObjectList.size(); i++)
	{
		if (gameObjectList[i] == gameObject)
		{
			this->gameObjectList.erase(this->gameObjectList.begin() + i);
			this->gameObjectMap.erase(gameObject->getName());
			isDeleted = true;
			cout << "object " << gameObject->getName() << " has been deleted\n";
			break;
		}

	}

	if (isDeleted == false)
	{
		cout << "this object does not exist\n";
	}

}

void GameObjectManager::deleteObjectByName(string name)
{
	AGameObject* temp = this->findObjectByName(name);

	if (temp != NULL)
	{
		this->deleteObject(temp);
	}
	else
	{
		cout << "an object with the name " << name << " does not exist\n";
	}
}

void GameObjectManager::deleteAllObjectsInScene()
{
	for (int i = 0; i < this->gameObjectList.size(); i++)
	{
		delete this->gameObjectList[i];
	}

	this->gameObjectList.clear();
	this->gameObjectList.shrink_to_fit();
	this->gameObjectMap.clear();
}
