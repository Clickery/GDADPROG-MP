#include <iostream>
#include "AGameObject.h"


AGameObject::AGameObject(string objName) {
	this->name = objName;
}

AGameObject::~AGameObject() {
	delete (this->entity);
}

string AGameObject::getName() {
	return this->name;
}

Entity* AGameObject::getEntity()
{
	return this->entity;
}

void AGameObject::attachChild(AGameObject* child) {
	this->childList.push_back(child);
	child->initialize();
	child->parent = this;
}

void AGameObject::detachChild(AGameObject* child) {
	int index = -1;
	for (int i = 0; i < this->childList.size(); i++) {
		if (this->childList[i] == child) {
			index = i;
		}
	}

	if (index != -1) {
		this->childList.erase(this->childList.begin() + index);
	}
}

void AGameObject::setPos(float x, float y) {
	this->entity->getSprite()->setPosition(x, y);
}

sf::FloatRect AGameObject::getLocalBounds()
{
	return this->entity->getSprite()->getLocalBounds();
}

sf::FloatRect AGameObject::getWorldBounds()
{
	sf::FloatRect bounds = this->entity->getSprite()->getGlobalBounds();

	if (this->parent != NULL)
		bounds = this->parent->getEntity()->getSprite()->getTransform().transformRect(bounds);

	return bounds;
}

AGameObject* AGameObject::getParent()
{
	return this->parent;
}

AGameObject::ObjectList AGameObject::getChildren()
{
	return this->childList;
}


void AGameObject::attachComponent(AComponent* component)
{
	this->componentList.push_back(component);
	component->attachOwner(this);
}

void AGameObject::detachComponent(AComponent* component)
{
	int index = -1;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i] == component) {
			this->componentList[i]->detachOwner();
			index = i;
		}
	}

	if (index != -1) {
		this->componentList.erase(componentList.begin() + index);
	}
}

AComponent* AGameObject::findComponentByName(string name)
{
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name) {
			return this->componentList[i];
		}
	}
	return NULL;
}

AComponent* AGameObject::findComponentOfType(AComponent::ComponentType type, string name)
{
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getName() == name && this->componentList[i]->getType() == type) {
			return this->componentList[i];
		}
	}
	return NULL;
}

AGameObject::ComponentList AGameObject::getComponentsOfType(AComponent::ComponentType type)
{
	ComponentList foundList;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}
	return foundList;
}

AGameObject::ComponentList AGameObject::getComponentsOfTypeRecursive(AComponent::ComponentType type)
{
	ComponentList foundList;
	for (int i = 0; i < this->componentList.size(); i++) {
		if (this->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}

	for (int i = 0; i < this->childList.size(); i++) {
		foundList = this->getComponentsRecursiveProper(this->childList[i], type, foundList);
	}
	return foundList;
}

AGameObject::ComponentList AGameObject::getComponentsRecursiveProper(AGameObject* object, AComponent::ComponentType type, ComponentList foundList)
{
	ObjectList children = object->childList;

	for (int i = 0; i < object->componentList.size(); i++) {
		if (object->componentList[i]->getType() == type) {
			foundList.push_back(this->componentList[i]);
		}
	}

	for (int i = 0; i < childList.size(); i++) {
		this->getComponentsRecursiveProper(childList[i], type, foundList);
	}

	return foundList;
}

void AGameObject::draw(sf::RenderWindow* window, sf::RenderStates renderStates) {
	// apply drawing with Parent-Child Relationship
	window->draw(*this->entity->getSprite(), renderStates); // draws the object first
	renderStates.transform = renderStates.transform * this->entity->getSprite()->getTransform(); // apply transform to children 
	//std::cout << "Drawing " + this->getName() << endl;

	// draw children 
	for (int i = 0; i < this->childList.size(); i++) {
		AGameObject* child = this->childList[i];
		child->draw(window, renderStates);
	}
}
