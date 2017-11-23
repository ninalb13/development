#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "UIElement.h"
#include "p2Point.h"
#include "p2SString.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes
enum UIType
{
	Button,
	TextBox,
	CheckBox,
	Picture,
	Label
};
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

	const SDL_Texture* GetAtlas() const;

	void AddElement(iPoint position, UIType type);

	p2List<UIElement*> elements;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;


};

#endif // __j1GUI_H__