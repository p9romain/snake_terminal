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
      Board(const int h, const int w, const int speed) ;


      int getStartRow() const ;
      int getStartCol() const ;
      chtype getCharAt(const int y, const int x) const ;
      void getEmptyCoord(int &y, int &x) const ;
      chtype getInput() const ;

      void setTO(const int t) const ;

      void init() const ;

      void addBorder() const ;
      void add(Draw d) const ;
      void addAt(const int y, const int x, const chtype c) const ;

      void clear() const ;
      void refresh() const ;
      
    protected :

    private :


  } ;

#endif // BOARD_HPP