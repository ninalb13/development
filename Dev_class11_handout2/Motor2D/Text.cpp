#include "Text.h"
#include "j1App.h"
#include "j1Fonts.h"


Text::Text()
{
}

Text::Text(int x, int y, const char * path_, int size_, UIElement::UIType type_)
{
	area.x = x;
	area.y = y;
	path = path_;
	size = size_;
	type = type_;

	font = App->font->Load(path_, size_);
	if (font != nullptr)
	{
		change = true;
	}
}


Text::~Text()
{
}

bool Text::PreUpdate()
{
	bool ret = true;
	if (font != nullptr && change) {
		if (change_font) {
			font = nullptr;
			font = App->font->Load(path, size);
			if (font == nullptr) {
				ret = false;
			}
			change_font = false;
		}

		ret = PrintText();
		change = false;
	}
	return ret;
}

bool Text::PostUpdate()
{
	if (font != nullptr) {
		App->render->Blit(texture, area.x, area.y, false);
		PrintText();
	}
	return true;
}
bool Text::PrintText()
{
	bool ret = true;
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}

	texture = App->font->Print(string.GetString(), color_, font);

	if (texture == nullptr)
		ret = false;

	return ret;
}

void Text::setString(const char* format)
{
	if (format != NULL)
	{
		static va_list  ap;
		static char tmp[TMP_STRING_SIZE];

		va_start(ap, format);
		int res = vsnprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);

		if (res > 0)
			string.create(tmp);

		
	}
}