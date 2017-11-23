#include "j1Module.h"
#include "p2Point.h"
#include "j1Textures.h"
#include "j1Gui.h"

#ifndef __UIELEMENT_H__
#define __UIELEMENT_H__
class UIElement
{
public:
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
	//UIType type;
	float opacity;

};

#endif 
