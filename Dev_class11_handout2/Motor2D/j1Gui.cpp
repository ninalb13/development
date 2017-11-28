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

	atlas = App->tex->Load(atlas_file_name.GetString());
	left_logo = App->tex->Load("Homework/Glues-Logo-Left.png");
	right_logo = App->tex->Load("Homework/Glues-Logo-Right.png");
	ESBR_logo = App->tex->Load("Homework/Glues-ESRBRating.png");

	AddPicture( 0, 0 , left_logo, UIElement::UIType::PICTURE);
	AddPicture(256, 0, right_logo, UIElement::UIType::PICTURE);
	AddPicture( 50, 583 , ESBR_logo, UIElement::UIType::PICTURE);
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
	for (p2List_item<Picture*>* iterator = pictures.start; iterator != NULL; iterator = iterator->next)
	{
		iterator->data->PostUpdate();
	}
	for (p2List_item<Text*>* iterator = text.start; iterator != NULL; iterator = iterator->next)
	{
		iterator->data->PostUpdate();
	}
	for (p2List_item<UIElement*>* iterator = elements.start; iterator != NULL; iterator = iterator->next)
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

Picture* j1Gui::AddPicture(int x, int y, SDL_Texture* texture_ ,UIElement::UIType type, SDL_Rect* rect_)
{
	Picture* aux = new Picture(x,y, texture_,type, rect_);
	
	pictures.add(aux);
	elements.add(aux);
	return aux;
}

Text * j1Gui::AddText(int x, int y, int size_, const char * path_, SDL_Color color, const char * content, UIElement::UIType type_)
{
	Text* aux = new Text(x,y, path_, size_, type_);
	aux->color_ = color;

	if (content != NULL)
	{
		va_list  ap;
		char buffer[TMP_STRING_SIZE];

		va_start(ap, content);
		int res = vsprintf_s(buffer, TMP_STRING_SIZE, content, ap);
		va_end(ap);

		if (res > 0) {
			aux->setString(buffer);
		}
	}
	text.add(aux);

	return aux;
}


// class Gui ---------------------------------------------------

