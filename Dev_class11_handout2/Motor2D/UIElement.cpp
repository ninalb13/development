#include "UIElement.h"



UIElement::UIElement()
{
}


UIElement::~UIElement()
{
}

bool UIElement::Awake(pugi::xml_node &)
{
	return true;
}

bool UIElement::Start()
{
	return true;
}

bool UIElement::PreUpdate()
{
	return false;
}

bool UIElement::PostUpdate()
{
	return true;
}

bool UIElement::CleanUp()
{
	return false;
}
