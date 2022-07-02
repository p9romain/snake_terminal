#ifndef BOARD_HPP
#define BOARD_HPP

  #include <ncurses.h>

  #include "Draw.hpp"

  class Board
  {
    WINDOW* bd_win ;
    int height, width, row, col ;
    
    public :
      Board() : Board(0, 0, 300) {}
      Board(int h, int w, int speed) ;


      int getStartRow() ;
      int getStartCol() ;
      chtype getCharAt(int y, int x) ;

      void init() ;

      void addBorder() ;
      void add(Draw d) ;
      void addAt(int y, int x, chtype c) ;

      void clear() ;
      void refresh() ;

      void getEmptyCoord(int &y, int &x) ;

      void setTO(int t) ;
      
      chtype getInput() ;

    protected :

    private :


  } ;

#endif // BOARD_HPP