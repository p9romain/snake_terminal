#include <ncurses.h>

#include "Score.hpp"

Scoreboard::Scoreboard()
{

}

Scoreboard::Scoreboard(int w, int y, int x)
{
  this->sc_win = newwin(2, w, y, w) ;
}

void Scoreboard::init(int highscore)
{
  (*this).clear() ;
  mvwprintw(this->sc_win, 0, 0, "Score :") ;
  mvwprintw(this->sc_win, 1, 0, "Highscore :") ;
  (*this).update(0, highscore) ;
  (*this).refresh() ;
}

void Scoreboard::update(int score, int highscore)
{
  mvwprintw(this->sc_win, 0, this->sc_win->_maxx - 10, "%11llu", score) ;
  mvwprintw(this->sc_win, 1, this->sc_win->_maxx - 10, "%11llu", highscore) ;
}

void Scoreboard::clear()
{
  wclear(this->sc_win) ;
}

void Scoreboard::refresh()
{
  wrefresh(this->sc_win) ;
}
