#ifndef BOARD_HPP
#define BOARD_HPP

  class Board
  {
    public :
      Board() : Board(0,0) {}
      Board(int h, int w) ;


      void init() ;
      void addBorder() ;
      void addAt(int y, int x, chtype c) ;
      void clear() ;
      void refresh() ;

      chtype getInput() ;

    protected :

    private :
      WINDOW* bd_win ;
  } ;

#endif // BOARD_HPP