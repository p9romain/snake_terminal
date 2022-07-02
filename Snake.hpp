#ifndef SNAKE_HPP
#define SNAKE_HPP

  #include <queue>

  #include "Draw.hpp"

  enum DIRECTION
  {
    UP = -1,
    DOWN = 1,
    LEFT = -2,
    RIGHT = 2,
  } ;

  class SnakePiece : public Draw
  {
    public :
      SnakePiece() : SnakePiece(0, 0) {}
      SnakePiece(int y, int x) : Draw(y, x, 'o') {}
  
    protected :
      
  
    private :
      
  } ;

  class Snake
  {
    std::queue<SnakePiece> body ;
    DIRECTION dir ;

    public :
      Snake() : dir{DIRECTION::UP} {}


      DIRECTION getDir() ;
      void setDir(DIRECTION d) ;

      void addPiece(SnakePiece sp) ;
      void removePiece() ;

      SnakePiece tail() ;
      SnakePiece head() ;
      SnakePiece nextHead() ;
  
    protected :
      
  
    private :


  } ;

#endif // SNAKE_HPP