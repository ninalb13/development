#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "Picture.h"
#include "UIElement.h"
#include "Text.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

// ---------------------------------------------------
class j1Gui : public j1Module
{

public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	SDL_Texture* GetAtlas();

	Picture * AddPicture(int x, int y, SDL_Texture * texture_, UIElement::UIType type, SDL_Rect* rect = NULL);
	Text* AddText(int x, int y, int size_, const char * path_, SDL_Color color, const char* content, UIElement::UIType type_);
	p2List<Picture*> pictures;
	p2List<Text*> text;
	p2List<UIElement*> elements;

private:

	SDL_Texture* atlas;
	SDL_Texture* left_logo;
	SDL_Texture* right_logo;
	SDL_Texture* ESBR_logo;
	p2SString atlas_file_name;



};

#endif // __j1GUI_H__