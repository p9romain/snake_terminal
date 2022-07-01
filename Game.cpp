#include <ncurses.h>
#include <cstdlib>

#include "Game.hpp"
#include "Board.hpp"
#include "Empty.hpp"
#include "Apple.hpp"

Game::Game(int h, int w) : bd{Board(h, w)}, game_over{false}
{
  this->apple = nullptr ;
  this->bd.init() ;

  std::srand(time_t(nullptr)) ;
}

Game::~Game()
{
  delete this->apple ;
}

void Game::input()
{
  chtype input = this->bd.getInput() ;
}

void Game::update()
{
  int y, x ;
  this->bd.getEmptyCoord(y, x) ;

  if ( apple != nullptr )
  {
    this->bd.add( Empty(this->apple->getY(), this->apple->getX()) ) ;
  }

  this->apple = new Apple(y, x) ;
  this->bd.add(*(this->apple)) ;
}

void Game::redraw()
{
  this->bd.refresh() ;
}

bool Game::isOver()
{
  return this->game_over ;
}
