#include <cstdlib>
#include <ncurses.h>
#include <iostream>

#include "Game.hpp"
#include "params.hpp"

int main( int argc, char **argv )
{
  std::srand(time(nullptr)) ;

  initscr() ;
  refresh() ;
  noecho() ;
  curs_set(0) ;

  Game game(HEIGHT, WIDTH, SPEED) ;
  int old_high = game.getHighscore() ;

  while( not game.isOver() )
  {
    game.input() ;
    game.update() ;
    game.redraw() ;
  }

  // add game over animation

  endwin() ;

  std::cout << std::endl ;
  std::cout << std::endl ;
  std::cout << std::endl ;

  std::cout << "   " << "Your score is " << game.getScore() << "." << std::endl ;
  if ( game.getScore() > old_high )
  {
    game.saveHighscore() ;
    std::cout << "   " << "You beat your old highscore ! Congratulation !" << std::endl ;
  }

  std::cout << std::endl ;
  std::cout << std::endl ;
  std::cout << std::endl ;

  return 0 ;
}