#include <ncurses.h>

#include "Game.hpp"

#define HEIGHT 12
#define WIDTH 30

int main( int argc, char **argv )
{
  initscr() ;
  refresh() ;

  noecho() ;

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