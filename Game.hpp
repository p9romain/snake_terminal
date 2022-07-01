#ifndef GAME_HPP
#define GAME_HPP

  #include "Board.hpp"

  class Game
  {
    public :
      Game(int h, int w) ;


      void input() ;
      void update() ;
      void redraw() ;

      bool isOver() ;

    protected :

    private :
      Board bd ;
      bool game_over ;
  } ;

#endif // GAME_HPP