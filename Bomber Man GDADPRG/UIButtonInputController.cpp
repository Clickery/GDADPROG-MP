#include "UIButtonInputController.h"
#include "UIButton.h"

UIButtonInputController::UIButtonInputController(string name, ButtonListener* buttonlistener) : GenericInputController(name)
{
	this->buttonListener = buttonlistener;
}

UIButtonInputController::~UIButtonInputController()
{
	AComponent::~AComponent();
}

void UIButtonInputController::perform()
{
	//cout << "Button " << this->name << "Clicked!\n";
	UIButton* button = (UIButton*)this->getOwner();
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && this->pressed)
	{
		this->pressed = false;
		button->changeButtontoNormal();
		this->buttonListener->onButtonReleased(button);
	}


	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		//check if button is within button
		sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
		sf::FloatRect bounds = button->getWorldBounds();

		if (bounds.contains(mousePos))
		{
			//cout << "mouse is inside button!!\n";
			this->pressed = true;
			button->changeButtonToPressed();
			this->buttonListener->onButtonClick(button);
		}
	}
}


ButtonListener::ButtonListener()
{
}

ButtonListener::~ButtonListener()
{
}

