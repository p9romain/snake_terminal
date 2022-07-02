#include <ncurses.h>

#include "Game.hpp"
#include "params.hpp"

int main( int argc, char **argv )
{
  initscr() ;
  refresh() ;
  noecho() ;
  curs_set(0) ;

  Game game(HEIGHT, WIDTH) ;

  while( not game.isOver() )
  {
    game.input() ;
    game.update() ;
    game.redraw() ;
  }

  endwin() ;

  return 0 ;
}