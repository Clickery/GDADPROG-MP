#include "PlayerInputController.h"

PlayerInputController::PlayerInputController(string name) : GenericInputController(name)
{

}

PlayerInputController::~PlayerInputController()
{
	GenericInputController::~GenericInputController();
}

void PlayerInputController::perform()
{

	//cout << "PlayerInputController is working!!!!\n";

	switch (event.type)
	{
		case sf::Event::KeyPressed: // KEY PRESSED
			
			if (event.key.code == sf::Keyboard::W) { // UP
				
				this->moveUp = true;
			}

			else if (event.key.code == sf::Keyboard::S) { // DOWN
				
				this->moveDown = true;
			}

			else if (event.key.code == sf::Keyboard::A) { // LEFT
				this->moveLeft = true;
			}

			else if (event.key.code == sf::Keyboard::D) { // RIGHT
				this->moveRight = true;
			}
			break;

		case sf::Event::KeyReleased: // KEY RELEASED
			if (event.key.code == sf::Keyboard::W) { // UP
				this->moveUp = false;
			}

			else if (event.key.code == sf::Keyboard::S) { // DOWN
				this->moveDown = false;
			}

			else if (event.key.code == sf::Keyboard::A) { // LEFT
				this->moveLeft = false;
			}

			else if (event.key.code == sf::Keyboard::D) { // RIGHT
				this->moveRight = false;
			}
			break;

		default:
			break;
	}
}

bool PlayerInputController::isUp()
{
	return this->moveUp;
}

bool PlayerInputController::isDown()
{
	return this->moveDown;
}

bool PlayerInputController::isLeft()
{
	return this->moveLeft;
}

bool PlayerInputController::isRight()
{
	return this->moveRight;
}
