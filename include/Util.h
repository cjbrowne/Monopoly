#ifndef UTIL_H
#define UTIL_H

class Util
{
public:
	Util();
	~Util();
	bool coordInsideRect(SDL_Rect rect, int x, int y);
};

#endif //UTIL_H