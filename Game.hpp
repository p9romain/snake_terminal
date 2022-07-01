#ifndef GAME_HPP
#define GAME_HPP

  #include "Board.hpp"
  #include "Apple.hpp"

  class Game
  {
    public :
      Game(int h, int w) ;
      ~Game() ;


      void input() ;
      void update() ;
      void redraw() ;

      bool isOver() ;

    protected :

    private :
      Board bd ;
      bool game_over ;
      Apple* apple ;
  } ;

#endif // GAME_HPP