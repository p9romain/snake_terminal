#ifndef SCORE_HPP
#define SCORE_HPP

  #include <ncurses.h>

  class Scoreboard
  {
    WINDOW* sc_win ;
  
    public :
      Scoreboard() ;
      Scoreboard(int w, int y, int x) ;


      void init(int highscore) ;
      void update(int score, int highscore) ;
      void clear() ;
      void refresh() ;
  
    protected :
      
  
    private :
      
  } ;

#endif // SCORE_HPP  