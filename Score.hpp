#ifndef SCORE_HPP
#define SCORE_HPP

  #include <ncurses.h>

  class Scoreboard
  {
    WINDOW* sc_win ;
  
    public :
      Scoreboard() ;
      Scoreboard(int w, int y, int x) ;


      void init() ;
      void update(int score) ;
      void clear() ;
      void refresh() ;
  
    protected :
      
  
    private :
      
  } ;

#endif // SCORE_HPP  