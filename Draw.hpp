#ifndef DRAW_CPP
#define DRAW_CPP

  #include <ncurses.h>

  class Draw
  {
    public :
      Draw() : Draw(0, 0, ' ') {}
      Draw(const int Y, const int X, const chtype chr) : y{Y}, x{X}, icon{chr} {}


      int getY() const ;
      int getX() const ;
      chtype getIcon() const ;
  
    protected :
      int y, x ;
      chtype icon ;
  
    private :
      
  } ;

#endif // DRAW_CPP