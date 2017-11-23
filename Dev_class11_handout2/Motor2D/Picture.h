#ifndef __PICTURE_H__
#define __PICTURE_H__

#include "UIElement.h"
#include "j1Render.h"

class Picture :
	public UIElement
{
public:
	Picture();
	~Picture();

	bool PostUpdate();

	void ChangeImage();
	SDL_Rect size;
	SDL_Texture* atlas;
};

#endif