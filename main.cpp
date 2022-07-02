#include <ncurses.h>
#include <iostream>

#include "Game.hpp"
#include "params.hpp"

int main( int argc, char **argv )
{
  initscr() ;
  refresh() ;
  noecho() ;
  curs_set(0) ;

  Game game(HEIGHT, WIDTH, SPEED) ;

  while( not game.isOver() )
  {
    game.input() ;
    game.update() ;
    game.redraw() ;
  }

  // add game over animation

  endwin() ;

  std::cout << "Game Over !" << std::endl ;
  std::cout << "Your score is " << game.getScore() << "." << std::endl ;

  return 0 ;
}