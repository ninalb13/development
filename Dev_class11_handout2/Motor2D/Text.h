
#ifndef __Text_H__
#define __Text_H__

#include "UIElement.h"


class Text :
	public UIElement
{
public:
	Text();
	Text(int x, int y, const char* path_, int size_);
	~Text();

	bool PostUpdate();


	//_TTF_Font* font = nullptr;
	p2SString string;
	//SDL_Color color;
	const char* path = nullptr;
	int size = 0;
	


};

#endif