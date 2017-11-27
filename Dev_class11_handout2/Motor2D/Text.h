
#ifndef __Text_H__
#define __Text_H__

#include "UIElement.h"


class Text :
	public UIElement
{
public:
	Text();
	Text(int x, int y, const char* path_, int size_, UIElement::UIType type_);
	~Text();

	bool PreUpdate();

	bool PrintText();

	void setString(const char * format);

	bool PostUpdate();


	_TTF_Font* font = nullptr;
	p2SString string;
	SDL_Color color_;
	const char* path = nullptr;
	int size = 0;
	bool change;
	bool change_font;
	


};

#endif