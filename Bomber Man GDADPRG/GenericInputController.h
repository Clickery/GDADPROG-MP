#pragma once
#include "AComponent.h"

class GenericInputController : public AComponent
{
public:
	GenericInputController(string name);
	~GenericInputController();
	void perform();
	void assignEvents(sf::Event event);

protected:
	sf::Event event;
};

