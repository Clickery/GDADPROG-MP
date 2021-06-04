#include "GenericInputController.h"
#include <iostream>

GenericInputController::GenericInputController(string name) : AComponent(name, Input)
{
	this->type = Input;
}

GenericInputController::~GenericInputController()
{
	AComponent::~AComponent();
}

void GenericInputController::perform()
{
	
}

void GenericInputController::assignEvents(sf::Event event)
{
	
	this->event = event;
}