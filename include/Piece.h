#ifndef PIECE_H
#define PIECE_H

class SDLGame;

enum Side
{
  SOUTH,
  WEST,
  NORTH,
  EAST
};

class Piece
{
public:
	Piece(std::string pieceName);
	~Piece();
	void render(SDL_Rect location);
	std::string name;
	void SDLInit(SDLGame* context);
        void loadImage(Side side);

	
private:
	SDL_Surface* image;
	SDL_Rect currentLocation;
	SDLGame* context;
};

#endif