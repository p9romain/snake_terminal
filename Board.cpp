#include <ncurses.h>

#include "Board.hpp"

Board::Board(int h, int w)
{
  int xMax, yMax ;
  getmaxyx(stdscr, yMax, xMax) ;

  this->bd_win = newwin(h, w, (yMax - h)/2, (xMax - w)/2) ;
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

chtype Board::getInput()
{
  return wgetch(this->bd_win) ;
}