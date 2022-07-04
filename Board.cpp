#include <ncurses.h>
#include <cstdlib>

#include "Board.hpp"
#include "Draw.hpp"

Board::Board(const int h, const int w, const int speed) : height{h}, width{w}
{
  int xMax, yMax ;
  getmaxyx(stdscr, yMax, xMax) ;

  this->row = (yMax - h)/2 ;
  this->col = (xMax - w)/2 ;

  this->bd_win = newwin(h, w, this->row, this->col) ;

  this->setTO(speed) ;

  keypad(this->bd_win, true) ;
}

int Board::getStartRow() const
{
  return this->row ;
}

int Board::getStartCol() const
{
  return this->col ;
}

chtype Board::getCharAt(const int y, const int x) const 
{
  return mvwinch(this->bd_win, y, x) ;
}

void Board::getEmptyCoord(int &y, int &x) const
{
  do
  {
    y = std::rand() % this->height ;
    x = std::rand() % this->width ;
  } while ( mvwinch(this->bd_win, y, x) != ' ' ) ;
}

chtype Board::getInput() const
{
  return wgetch(this->bd_win) ;
}

void Board::setTO(const int t) const
{
  wtimeout(this->bd_win, t) ;
}

void Board::init() const
{
  (*this).clear() ;
  (*this).refresh() ;
}

void Board::addBorder() const
{
  box(this->bd_win, 0, 0) ;
}

void Board::add(Draw d) const
{
  (*this).addAt(d.getY(), d.getX(), d.getIcon()) ;
}

void Board::addAt(const int y, const int x, const chtype c) const
{
  mvwaddch(this->bd_win, y, x, c) ;
}

void Board::clear() const
{
  wclear(this->bd_win) ;
  (*this).addBorder() ;
}

void Board::refresh() const
{
  wrefresh(this->bd_win) ;
}