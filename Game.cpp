#include <cstdlib>
#include <ncurses.h>

#include "Game.hpp"
#include "Board.hpp"
#include "params.hpp"
#include "Snake.hpp"
#include "Empty.hpp"
#include "Apple.hpp"
#include "Score.hpp"

Game::Game(int h, int w, int speed) : bd{Board(h, w, speed)}, game_over{false}, score{0}
{
  std::srand(time_t(nullptr)) ;

  int sb_row = this->bd.getStartRow() + h ; 
  int sb_col = this->bd.getStartCol() ;
  this->sb = Scoreboard(w, sb_row, sb_col) ;

  this->apple = nullptr ;
  this->bd.init() ;
  this->sb.init() ;

  int n = std::min((HEIGHT*WIDTH)/250, HEIGHT/2 - 2) ;

  (*this).handleNextPiece(SnakePiece(HEIGHT/2 + n - 1, WIDTH/2 - 1)) ;
  
  for ( int i = 1 ; i < n ; i++ )
  {
    (*this).handleNextPiece(this->snake.nextHead()) ;
  }

  if ( this->apple == nullptr )
  {
    (*this).createApple() ;
  }
}

Game::~Game()
{
  delete this->apple ;
}

int Game::getScore()
{
  return this->score ;
}

void Game::input()
{
  chtype input = this->bd.getInput() ;
  switch (input)
  {
    case KEY_UP :
    case 'z' :
    case 'Z' :
    {
      this->snake.setDir(DIRECTION::UP) ;
      break ;
    }
  
    case KEY_DOWN :
    case 's' :
    case 'S' :
    {
      this->snake.setDir(DIRECTION::DOWN) ;
      break ;
    }
  
    case KEY_LEFT :
    case 'q' :
    case 'Q' :
    {
      this->snake.setDir(DIRECTION::LEFT) ;
      break ;
    }
  
    case KEY_RIGHT :
    case 'd' :
    case 'D' :
    {
      this->snake.setDir(DIRECTION::RIGHT) ;
      break ;
    }

    case 'p' :
    case 'P' :
    {
      this->bd.setTO(-1) ;
      
      // add pause text
      
      while ( this->bd.getInput() != 'p' and this->bd.getInput() != 'P' )
      {

      }

      // clear pause text

      this->bd.setTO(SPEED) ;
      break ;
    }
  }
}

void Game::update()
{
  (*this).handleNextPiece(this->snake.nextHead()) ;

  if ( this->apple == nullptr )
  {
    (*this).createApple() ;
  }
}

void Game::redraw()
{
  this->bd.refresh() ;
  this->sb.refresh() ;
}

bool Game::isOver()
{
  return this->game_over ;
}



void Game::handleNextPiece(SnakePiece p)
{
  if ( this->apple != nullptr )
  {
    switch ( this->bd.getCharAt(p.getY(), p.getX()) )
    {
      case '@' :
      {
        (*this).eatApple() ;
        break ;
      }
    
      case ' ' :
      {
        int emptyX = this->snake.tail().getX() ;
        int emptyY = this->snake.tail().getY() ;

        this->bd.add( Empty(emptyY, emptyX) ) ;
        this->snake.removePiece() ;
        break ;
      }

      default :
      {
        this->game_over = true ;
      }
    }
  }

  this->bd.add(p) ;
  this->snake.addPiece(p) ;
}

void Game::createApple()
{
  int y, x ;
  this->bd.getEmptyCoord(y, x) ;
  this->apple = new Apple(y, x) ;
  this->bd.add(*(this->apple)) ;
}

void Game::eatApple()
{
  delete this->apple ;
  this->apple = nullptr ;

  this->score += 50 ;
  this->sb.update(this->score) ;
}