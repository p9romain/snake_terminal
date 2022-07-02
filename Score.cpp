#include <ncurses.h>

#include "Score.hpp"

Scoreboard::Scoreboard()
{

}

Scoreboard::Scoreboard(int w, int y, int x)
{
  this->sc_win = newwin(1, w, y, w) ;
}

void Scoreboard::init()
{
  (*this).clear() ;
  mvwprintw(this->sc_win, 0, 0, "Score :") ;
  (*this).update(0) ;
  (*this).refresh() ;
}

void Scoreboard::update(int score)
{
  mvwprintw(this->sc_win, 0, this->sc_win->_maxx - 10, "%11llu", score) ;
}

void Scoreboard::clear()
{
  wclear(this->sc_win) ;
}

void Scoreboard::refresh()
{
  wrefresh(this->sc_win) ;
}
