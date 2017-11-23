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

	void ChangeImage();
	SDL_Rect size;
};

#endif