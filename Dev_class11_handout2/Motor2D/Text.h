
#ifndef __Text_H__
#define __Text_H__

#include "UIElement.h"
#include "j1Fonts.h"

class Text :
	public UIElement
{
public:
	Text();
	~Text();

private:

	_TTF_Font* font = nullptr;
	p2SString string;
	SDL_Color color;

};

#endif