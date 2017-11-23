#include "Picture.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Gui.h"
Picture::Picture()
{
}


Picture::~Picture()
{
}

bool Picture::PostUpdate()
{
	atlas = App->gui->GetAtlas();
	size = { 485, 829, 328, 103 };
	App->render->Blit(atlas, position.x, position.y, &size,1.0f,0.0, INT_MAX, INT_MAX, false);
	return true;
}

void Picture::ChangeImage()
{
}
