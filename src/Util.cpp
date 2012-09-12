#include <SDL/SDL.h>
#include "Util.h"

Util::Util()
{

}

Util::~Util()
{

}

bool Util::coordInsideRect(SDL_Rect rect, int x, int y)
{
	if(x >= rect.x 
		&& x <= rect.x + rect.w
		&& y >= rect.y
		&& y <= rect.y + rect.h)
		return true;
	return false;
}