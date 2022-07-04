#ifndef DRAW_CPP
#define DRAW_CPP

  #include <ncurses.h>

  class Draw
  {
    public :
      Draw() : Draw(0, 0, ' ') {}
      Draw(int Y, int X, chtype chr) : y{Y}, x{X}, icon{chr} {}


      int getY() ;
      int getX() ;
      
      chtype getIcon() ;
  
    protected :
      int y, x ;
      chtype icon ;
  
    private :
      
  } ;

#endif // DRAW_CPP