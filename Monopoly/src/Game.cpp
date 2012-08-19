/*
 * Game.cpp
 *
 *  Created on: 18 aug 2012
 *      Author: Chris Browne
 */

#include <iostream>
#include "Game.h"

Game::Game(Rules rules,unsigned int numPlayers)
{
  this->isOver = false;
  if(numPlayers < 2)
  {
    std::cerr << "Nonsense game requested, exiting.";
    this->isOver = true;
    return;
  }
  this->rules = rules;
  this->numPlayers = 0;
  currentPlayer = new Player();
  Player* firstPlayer = currentPlayer;
  do
  {
    currentPlayer->next = new Player();
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
  while(!isOver)
  {
    takeTurn();
  }
}

void Game::takeTurn()
{
  dice.roll();
  currentPlayer = currentPlayer->next;
}


