/*
 * Game.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 *
 *
 *
 * FIXME: currently allows two players to choose to be the same piece, this behaviour must be rectified
 * NOTE: this is the command-line, testing version of the Game class.  A replacement, SDL version is in the planning phase.
 */

#include <iostream>
#include "HumanAgent.h"
#include "ComputerAgent.h"
#include "Game.h"

Game::Game(Rules rules, unsigned int numPlayers)
{
    std::string playerNameBuffer;
    std::string pieceNameBuffer;
    bool humanBuffer;
    this->isOver = false;
    if (numPlayers < 2 || numPlayers > 8)
    {
	std::cerr << "Nonsense game requested, exiting.";
	this->isOver = true;
	return;
    }
    this->rules = rules;
    this->numPlayers = 1;
    std::cout << "Player 1, what is your name? ";
    std::cin >> playerNameBuffer;
    do
    {
    std::cout << "Player 1, what piece would you like? ";
    std::cin >> pieceNameBuffer;
    } while (pieceNameToType(pieceNameBuffer) == BAD_CHOICE);
    std::cout << "Is player 1 a human player? ";
    std::cin >> humanBuffer;
    currentPlayer = new Player(playerNameBuffer,pieceNameToType(pieceNameBuffer));
    currentPlayer->controller = (humanBuffer?(Agent*)new HumanAgent():(Agent*)new ComputerAgent());
    Player* firstPlayer = currentPlayer;
    do
    {
	std::cout << "Player " << numPlayers << ", what is your name? ";
	std::cin >> playerNameBuffer;
	do
	{
	std::cout << "Player " << numPlayers << ", what piece would you like? ";
	std::cin >> pieceNameBuffer;
	} while(pieceNameToType(pieceNameBuffer) == BAD_CHOICE);
	std::cout << "Is player " << numPlayers << " a human player? ";
	std::cin >> humanBuffer;
	currentPlayer->next = new Player(playerNameBuffer,pieceNameToType(pieceNameBuffer));
	currentPlayer = currentPlayer->next;
	this->numPlayers++;
    } while (this->numPlayers < numPlayers);
    currentPlayer->next = firstPlayer;
}

Game::~Game()
{
    // TODO Auto-generated destructor stub
}

void Game::start()
{
    while (!isOver)
    {
	takeTurn();
    }
}

void Game::takeTurn()
{
    if(currentPlayer->controller->isHuman)
	((HumanAgent*)(currentPlayer->controller))->takeTurn(currentPlayer,board);
    else
	((ComputerAgent*)(currentPlayer->controller))->takeTurn(currentPlayer,board);

    dice.roll();
    std::cout << currentPlayer->name << " rolls: ";
    dice.print();



    currentPlayer = currentPlayer->next;
}

Piece Game::pieceNameToType(std::string name)
{
    if(name.compare("car") == 0) return CAR;
    if(name.compare("boat") == 0) return BOAT;
    if(name.compare("dog") == 0) return DOG;
    if(name.compare("top hat") == 0) return TOP_HAT;
    if(name.compare("iron") == 0) return IRON;
    if(name.compare("wheelbarrow") == 0) return WHEELBARROW;
    if(name.compare("horse") == 0) return HORSE;
    if(name.compare("thimble") == 0) return THIMBLE;
    std::cout << "Valid options:\n";
    std::cout << "\tcar\n"
	      << "\tboat\n"
	      << "\tdog\n"
	      << "\ttop hat\n"
	      << "\tiron\n"
	      << "\twheelbarrow\n"
	      << "\thorse\n"
	      << "\tthimble\n";
    return BAD_CHOICE;
}


