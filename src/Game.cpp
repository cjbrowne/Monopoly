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

/*
 * Pretty basic string->bool conversion function
 * Could probably flesh it out but it's only used in testing (the SDL version of this class won't need a string-to-bool function)
 */
bool toBool(std::string from)
{
    return (from == "true" || from == "yes" || from == "1" || from == "y");
}

Game::Game(Rules rules, unsigned int numPlayers)
{
    std::string playerNameBuffer;
    std::string pieceNameBuffer;
    std::string humanBuffer;
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
    currentPlayer->controller = (toBool(humanBuffer)?(Agent*)new HumanAgent():(Agent*)new ComputerAgent());
    firstPlayer = currentPlayer;
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
	currentPlayer->next->controller = (toBool(humanBuffer)?(Agent*)new HumanAgent():(Agent*)new ComputerAgent());
	currentPlayer = currentPlayer->next;
	this->numPlayers++;
    } while (this->numPlayers < numPlayers);
    currentPlayer->next = firstPlayer;
    printPlayerList();
}

void Game::printPlayerList()
{
    Player* rewindPoint = currentPlayer;
    currentPlayer = firstPlayer;
    do
    {
	std::cout << currentPlayer->name << " is playing as the " << pieceTypeToName(currentPlayer->piece) << "\n";
	currentPlayer = currentPlayer->next;
    } while(currentPlayer != firstPlayer);
    currentPlayer = rewindPoint;
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
	((HumanAgent*)(currentPlayer->controller))->takeTurn(currentPlayer,board,dice);
    else
	((ComputerAgent*)(currentPlayer->controller))->takeTurn(currentPlayer,board,dice);
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

std::string Game::pieceTypeToName(Piece type)
{
    switch(type)
    {
	case CAR:
	    return "car";
	case BOAT:
	    return "boat";
	case DOG:
	    return "dog";
	case TOP_HAT:
	    return "top hat";
	case IRON:
	    return "iron";
	case WHEELBARROW:
	    return "wheelbarrow";
	case HORSE:
	    return "horse";
	case THIMBLE:
	    return "thimble";
	default:
	    return "unknown";
    }
}

Game::~Game()
{
    // TODO Auto-generated destructor stub
}
