#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "UIElement.h"
#include "Picture.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
	
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	iPoint position_ = { 0,0 };
	atlas = App->tex->Load(atlas_file_name.GetString());
	AddPicture(position_, UIElement::UIType::PICTURE);
	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	for (p2List_item<Picture*>* iterator = elements.start; iterator != NULL; iterator = iterator->next)
	{
		iterator->data->PostUpdate();
	}
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas()
{
	return atlas;
}

Picture* j1Gui::AddPicture(iPoint position, UIElement::UIType type)
{
	Picture* aux = new Picture;
	aux->position = position;
	aux->type = type;

	elements.add(aux);
	return aux;
}

// class Gui ---------------------------------------------------

