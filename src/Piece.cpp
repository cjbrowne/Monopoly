/*
TODO - separate out SDL and non-SDL versions of this file using preprocessor commands or a modified build system
     (I'm just too lazy to do it at the moment)
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <sstream>
#include "Piece.h"
#include "SDLGame.h"

Piece::Piece(std::string pieceName)
{
	// pieces should be 62x50 pixels
	currentLocation.w = 62;
	currentLocation.h = 50;

	// these should be set to invalid drawing locations so that the first draw attempt happens
	currentLocation.x = -1;
	currentLocation.y = -1;
	context = NULL;
	name = pieceName;
}

Piece::~Piece()
{

}

void Piece::SDLInit(SDLGame* context)
{
	this->context = context;
        // by default, we assume to be on the Go square
	loadImage(SOUTH);
}

void Piece::loadImage(Side side)
{
  std::stringstream imageLocation;
  imageLocation << "img/themes/" << context->theme << name;
  switch(side)
  {
    case SOUTH:
      imageLocation << "_south.png";
      break;
    case WEST:
      imageLocation << "_west.png";
      break;
    case NORTH:
      imageLocation << "_north.png";
      break;
    case EAST:
      imageLocation << "_east.png";
      break;
    default:
      imageLocation << ".png";
  }
  SDL_Surface* imageTMP = IMG_Load(imageLocation.str().c_str());
  if(imageTMP == NULL)
  {
    imageTMP = IMG_Load("img/missing.png");
  }
  image = SDL_DisplayFormatAlpha(imageTMP);
}

inline bool locationChanged(SDL_Rect a,SDL_Rect b)
{
	return !(a.x == b.x && a.y == b.y);
}

// NOTE: this is intended NOT to copy the w and h properties
inline void copyRect(SDL_Rect* dest,SDL_Rect src)
{
	dest->x = src.x;
	dest->y = src.y;
}

void Piece::render(SDL_Rect location)
{
	if(context == NULL)
	{
		#if DEBUG > 1
		std::cerr << "Warning: Could not render piece, problem establishing game context\n";
		#endif
		return;
	}
	if(locationChanged(location,currentLocation))
	{
		copyRect(&currentLocation,location);
		SDL_BlitSurface(image,NULL,context->getRenderContext(),&currentLocation);
		context->screenUpdated = true;
	}
}