#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__

#include "j1Module.h"
#include "p2Point.h"
#include "j1Render.h"
#include "j1Fonts.h"
struct SDL_Texture;
class UIElement
{
public:
	enum Alignment
	{
		RIGHT,
		LEFT,
		CENTERED
	};
	enum UIType
	{
		BUTTON,
		TEXT,
		CHECKBOX,
		PICTURE,
		LABEL
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


	SDL_Rect area;
	//iPoint position;
	SDL_Texture* texture;
	UIType type;
	float opacity;

};

#endif 
