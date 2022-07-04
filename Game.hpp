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
      Game(const int h, const int w, const int speed) ;
      ~Game() ;


      int readHighscore() const ;
      int getHighscore() const ;
      int getScore() const ;

      void saveHighscore() const ;

      void input() ;
      void update() ;
      void redraw() const ;

      bool isOver() const ;

    protected :


    private :
      void handleNextPiece(const SnakePiece p) ;

      void createApple() ;
      void eatApple() ;

  } ;

#endif // GAME_HPP