#ifndef GAME_HPP
#define GAME_HPP

  #include "Board.hpp"
  #include "Apple.hpp"
  #include "Snake.hpp"
  #include "Score.hpp"

  class Game
  {
    Board bd ;
    bool game_over ;
    Apple* apple ;
    Snake snake ;

    Scoreboard sb ;
    int score ;

    public :
      Game(int h, int w, int speed) ;
      ~Game() ;


      int getScore() ;

      void input() ;
      void update() ;
      void redraw() ;

      bool isOver() ;

    protected :


    private :
      void handleNextPiece(SnakePiece p) ;

      void createApple() ;
      void eatApple() ;

  } ;

#endif // GAME_HPP