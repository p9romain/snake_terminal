#ifndef SCORE_HPP
#define SCORE_HPP

  #include <ncurses.h>

  class Scoreboard
  {
    WINDOW* sc_win ;
  
    public :
      Scoreboard() ;
      Scoreboard(const int w, const int y, const int x) ;


      void init(const int highscore) const ;
      void update(const int score, const int highscore) const ;
      void clear() const ;
      void refresh() const ;
  
    protected :
      
  
    private :
      
  } ;

#endif // SCORE_HPP  