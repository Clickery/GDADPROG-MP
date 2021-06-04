#include "AComponent.h"

AComponent::AComponent(string name, ComponentType type)
{
	this->name = name;
	this->type = type;
	this->owner = NULL;
}

AComponent::~AComponent()
{
	this->owner = NULL;
	this->type = NotSet;
}

void AComponent::attachOwner(AGameObject* owner)
{
	this->owner = owner;
}

void AComponent::detachOwner()
{
	delete this;
}

AGameObject* AComponent::getOwner()
{
	return this->owner;
}

AComponent::ComponentType AComponent::getType()
{
	return this->type;
}

string AComponent::getName()
{
	return this->name;
}

void AComponent::setDeltaTime(sf::Time deltaTime)
{
	this->deltaTime = deltaTime;
}


