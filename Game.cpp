#include <ncurses.h>
#include <cstdlib>

#include "Game.hpp"
#include "Board.hpp"
#include "Draw.hpp"

Game::Game(int h, int w) : bd{Board(h, w)}, game_over{false}
{
  this->bd.init() ;

  std::srand(time(nullptr)) ;
}

void Game::input()
{
  chtype input = this->bd.getInput() ;
}

void Game::update()
{
  this->bd.add(Draw(3, 3, 'X')) ;
}

void Game::redraw()
{
  this->bd.refresh() ;
}

bool Game::isOver()
{
  return this->game_over ;
}
