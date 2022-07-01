#include <ncurses.h>
#include <cstdlib>

#include "Game.hpp"
#include "Board.hpp"
#include "Snake.hpp"
#include "params.hpp"
#include "Empty.hpp"
#include "Apple.hpp"

Game::Game(int h, int w) : bd{Board(h, w)}, game_over{false}
{
  std::srand(time_t(nullptr)) ;

  this->apple = nullptr ;
  this->bd.init() ;

  SnakePiece next((HEIGHT)/2 + 3, WIDTH/2 - 1) ;

  for ( int i = 0 ; i < 4 ; i++ )   
  {
    this->bd.add(next) ;
    this->snake.addPiece(next) ;

    if ( i == 3 )
    {
      break ;
    }

    next = this->snake.nextHead() ;
  }
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
  if ( apple == nullptr )
  {
    int y, x ;
    this->bd.getEmptyCoord(y, x) ;
    this->apple = new Apple(y, x) ;
    this->bd.add(*(this->apple)) ;
  }

  SnakePiece next = this->snake.nextHead() ;
  if ( next.getX() != this->apple->getX() and next.getY() != this->apple->getY() )
  {
    int emptyX = this->snake.tail().getX() ;
    int emptyY = this->snake.tail().getY() ;

    this->bd.add( Empty(emptyY, emptyX) ) ;
    this->snake.removePiece() ;
  }

  this->bd.add(next) ;
  this->snake.addPiece(next) ;
}

void Game::redraw()
{
  this->bd.refresh() ;
}

bool Game::isOver()
{
  return this->game_over ;
}
