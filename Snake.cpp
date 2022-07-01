#include "Snake.hpp"

DIRECTION Snake::getDir()
{
  return this->dir ;
}

void Snake::setDir(DIRECTION d)
{
  this->dir = d ;
}

void Snake::addPiece(SnakePiece p)
{
  this->body.push(p) ;
}

void Snake::removePiece()
{
  this->body.pop() ;
}

SnakePiece Snake::tail()
{
  return this->body.back() ;
}

SnakePiece Snake::head()
{
  return this->body.front() ;
}

SnakePiece Snake::nextHead()
{
  int y = (*this).head().getX() ;
  int x = (*this).head().getY() ;

  switch (this->dir)
  {
    case DIRECTION::DOWN :
      y++ ;
      break ;
  
    case DIRECTION::UP :
      y-- ;
      break ;
  
    case DIRECTION::RIGHT :
      x++ ;
      break ;
  
    case DIRECTION::LEFT :
      x-- ;
      break ;
  }

  return SnakePiece(y, x) ;
}