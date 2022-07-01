#include <ncurses.h>
#include <cstdlib>

#include "Board.hpp"
#include "Draw.hpp"

Board::Board(int h, int w) : height{h}, width{w}
{
  int xMax, yMax ;
  getmaxyx(stdscr, yMax, xMax) ;

  this->bd_win = newwin(h, w, (yMax - h)/2 - 1, (xMax - w)/2) ;

  wtimeout(this->bd_win, 1000) ;
}

void Board::init()
{
  (*this).clear() ;
  (*this).refresh() ;
}

void Board::addBorder()
{
  box(this->bd_win, 0, 0) ;
}

void Board::add(Draw d)
{
  (*this).addAt(d.getY(), d.getX(), d.getIcon()) ;
}

void Board::addAt(int y, int x, chtype c)
{
  mvwaddch(this->bd_win, y, x, c) ;
}

void Board::clear()
{
  wclear(this->bd_win) ;
  (*this).addBorder() ;
}

void Board::refresh()
{
  wrefresh(this->bd_win) ;
}

void Board::getEmptyCoord(int &y, int &x)
{
  do
  {
    y = std::rand() % this->height ;
    x = std::rand() % this->width ;
  } while ( mvwinch(this->bd_win, y, x) != ' ' ) ;
}

chtype Board::getInput()
{
  return wgetch(this->bd_win) ;
}