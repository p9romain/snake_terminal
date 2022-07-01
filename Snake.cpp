#include "Snake.hpp"

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