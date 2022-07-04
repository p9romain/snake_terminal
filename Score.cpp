#include <ncurses.h>

#include "Score.hpp"

Scoreboard::Scoreboard()
{

}

Scoreboard::Scoreboard(const int w, const int y, const int x)
{
  this->sc_win = newwin(2, w, y, w) ;
}

void Scoreboard::init(const int highscore) const
{
  (*this).clear() ;
  mvwprintw(this->sc_win, 0, 0, "Score :") ;
  mvwprintw(this->sc_win, 1, 0, "Highscore :") ;
  (*this).update(0, highscore) ;
  (*this).refresh() ;
}

void Scoreboard::update(const int score, const int highscore) const
{
  mvwprintw(this->sc_win, 0, this->sc_win->_maxx - 10, "%11llu", score) ;
  mvwprintw(this->sc_win, 1, this->sc_win->_maxx - 10, "%11llu", highscore) ;
}

void Scoreboard::clear() const
{
  wclear(this->sc_win) ;
}

void Scoreboard::refresh() const
{
  wrefresh(this->sc_win) ;
}
