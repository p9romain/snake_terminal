#ifndef GAME_HPP
#define GAME_HPP

  #include "Board.hpp"
  #include "Apple.hpp"
  #include "Snake.hpp"

  class Game
  {
    Board bd ;
    bool game_over ;
    Apple* apple ;
    Snake snake ;

    public :
      Game(int h, int w) ;
      ~Game() ;


      void input() ;
      void update() ;
      void redraw() ;

      bool isOver() ;

    protected :


    private :


  } ;

#endif // GAME_HPP