#ifndef BOARD_HPP
#define BOARD_HPP

  #include <ncurses.h>

  #include "Draw.hpp"

  class Board
  {
    WINDOW* bd_win ;
    int height, width ;
    
    public :
      Board() : Board(0, 0) {}
      Board(int h, int w) ;


      void init() ;

      void addBorder() ;
      void add(Draw d) ;
      void addAt(int y, int x, chtype c) ;

      void clear() ;
      void refresh() ;

      void getEmptyCoord(int &y, int &x) ;
      
      chtype getInput() ;

    protected :

    private :


  } ;

#endif // BOARD_HPP