#include <ncurses.h>

#include "Board.hpp"
#include "Game.hpp"

Game::Game(int h, int w)
{
  this->bd = Board(h, w) ;
  this->bd.init() ;

  this->game_over = false ;
}

void Game::input()
{
  chtype input = this->bd.getInput() ;
}

void Game::update()
{
  
}


void Game::redraw()
{
  this->bd.refresh() ;
}


bool Game::isOver()
{
  return this->game_over ;
}
