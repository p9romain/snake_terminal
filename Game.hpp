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
    int highscore ;

    public :
      Game(int h, int w, int speed) ;
      ~Game() ;


      int readHighscore() ;
      int getHighscore() ;
      int getScore() ;

      void saveHighscore() ;

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