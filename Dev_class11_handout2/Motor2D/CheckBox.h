
#ifndef __CHECKBOX_H__
#define __CHECKBOX_H__

#include "UIElement.h"
#include "j1Render.h"

class CheckBox :
	public UIElement
{
public:
	CheckBox();
	~CheckBox();

	SDL_Rect unchecked;
	SDL_Rect checked;


	void SwitchChecked();
};

#endif