

#ifndef __BUTTON_H__
#define __BUTTON_H__
#include "UIElement.h"
#include "j1Textures.h"


class Button :
	public UIElement
{
	SDL_Texture* hover;
	SDL_Texture* clicked;
	//Label text;

public:
	Button();
	~Button();

	void OnClick();
	void CheckHover();
	void CheckClick();
};

#endif