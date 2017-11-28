#include "Picture.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"
Picture::Picture()
{
}

Picture::Picture(int x, int y, SDL_Texture* texture_, UIElement::UIType type_, SDL_Rect* rect_)
{
	area.x = x;
	area.y = y;
	area.w = 0;
	area.h = 0;
	texture = texture_;
	type = type_;
	if (rect_ != NULL)
	{
		size = *rect_;
	}
	else
	{
		SDL_Rect rect;
		rect.x = 0;
		rect.y = 0;
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
		size = rect;
	}

}

Picture::~Picture()
{
}

bool Picture::PostUpdate()
{

	App->render->Blit(texture, area.x, area.y, &size,1.0f,0.0, INT_MAX, INT_MAX, false);
	return true;
}

void Picture::ChangeImage()
{
}
