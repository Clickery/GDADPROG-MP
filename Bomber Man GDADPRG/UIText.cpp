#include "UIText.h"

UIText::UIText(string name) :AGameObject(name)
{

}

UIText::~UIText()
{
	delete this->text->getFont();
	delete this->text;
	AGameObject::~AGameObject();
}

void UIText::initialize()
{
	//declare a text to be used
	//font must be a pointer or else it gets immediately de-allocated
	sf::Font* font = TextureManager::getInstance()->getFont(TextureManager::FontType::DefaultFont);
	this->text = new sf::Text;
	this->text->setFont(*font);
	this->setSize(40);
	this->setStyle(sf::Color::White, sf::Color::Black, 4.0f);
	this->text->setString("<Using placeholder!>");
}

//override draw from AGameObject
void UIText::draw(sf::RenderWindow* targetWindow, sf::RenderStates renderStates)
{
	//apply drawing with parent-child  relationship
	targetWindow->draw(*this->text, renderStates);
	renderStates.transform = renderStates.transform * this->text->getTransform(); // transform for children

	//draw children
	for (int i = 0; i < this->childList.size(); i++)
	{
		AGameObject* child = this->childList[i];
		child->draw(targetWindow, renderStates);
	}
}

void UIText::setText(string text)
{
	//align to center
	this->text->setString(text);
	this->text->setOrigin(this->text->getLocalBounds().left +
		this->text->getLocalBounds().width / 2, this->text->getLocalBounds().top +
		this->text->getLocalBounds().height / 2);
}

void UIText::setStyle(sf::Color fillcolor, sf::Color outlineColor, float outlineThickness)
{
	this->text->setFillColor(fillcolor);
	this->text->setOutlineColor(outlineColor);
	this->text->setOutlineThickness(outlineThickness);
}

void UIText::setSize(int size)
{
	this->text->setCharacterSize(size);
}

void UIText::setPosition(float x, float y)
{
	this->text->setPosition(x, y);
}

void UIText::setScale(float x, float y)
{
	this->text->setScale(x, y);
}

sf::Vector2f UIText::getPosition()
{
	return this->text->getPosition();
}

sf::Vector2f UIText::getScale()
{
	return this->text->getScale();
}

string UIText::getText()
{
	return this->text->getString();
}
