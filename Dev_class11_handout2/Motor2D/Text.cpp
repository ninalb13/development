#include "Text.h"



Text::Text()
{
}

Text::Text(int x, int y, const char * path_, int size_)
{
	area.x = x;
	area.y = y;
	path = path_;
	size = size_;
}


Text::~Text()
{
}
