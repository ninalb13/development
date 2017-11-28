
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "UIElement.h"
#include "j1Textures.h"
#include "Picture.h"
#include "Text.h"

class Button :
	public UIElement
{
	SDL_Texture* hover;
	SDL_Texture* clicked;
	//Label text;

public:
	Button();
	Button(int x, int y, SDL_Texture* texture_, UIElement::UIType type_);
	Button(Picture picture_, Text text);
	~Button();

	void OnClick();
	void CheckHover();
	void CheckClick();


private:
	Picture pic;
	Text txt;
};

#endif