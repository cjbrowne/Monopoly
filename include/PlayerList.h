#ifndef PLAYER_LIST_H
#define PLAYER_LIST_H

class Player;

struct PlayerListItem
{
	Player* current;
	PlayerListItem* next;
};

class PlayerList
{
public:
	PlayerList();
	~PlayerList();
	void add(Player* player);
	void del(Player* player);
	PlayerListItem* top;
};


#endif