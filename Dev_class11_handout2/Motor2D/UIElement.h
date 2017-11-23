#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "j1Module.h"
#include "p2Point.h"

struct SDL_Texture;

class UIElement
{
public:
	enum UIType
	{
		Button,
		TextBox,
		CheckBox,
		Picture,
		Label
	};

	UIElement();
	~UIElement();

	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


	iPoint position;
	SDL_Texture* texture;
	UIType type;
	float opacity;

};

#endif 
