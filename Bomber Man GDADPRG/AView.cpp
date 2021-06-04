#include "AView.h"

AView::AView(string name) : AGameObject(name)
{
	this->name = name;
}

AView::~AView()
{
	AGameObject::~AGameObject();
}
