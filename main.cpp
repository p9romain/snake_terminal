#include <iostream>
#include <vector>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC 27

#define KEY_Z 90
#define KEY_S 83
#define KEY_Q 81
#define KEY_D 68
#define KEY_X 88

#define KEY_z 122
#define KEY_s 115
#define KEY_q 113
#define KEY_d 100
#define KEY_x 120


bool gameOver ;
// height x width
const std::vector<int> sizeGrid = std::vector<int>{{ 30, 60 }} ;

std::vector<int> fruitPos = std::vector<int>{} ;
std::vector<int> pos = std::vector<int>{} ;
int score ;
enum DIRECTION { STOP = 0, UP, DOWN, LEFT, RIGHT } ;
DIRECTION dir ;

void setup()
{
  gameOver = false ;
  dir = DIRECTION::STOP ;

  pos.push_back(sizeGrid.at(0) / 2) ;
  pos.push_back(sizeGrid.at(1) / 2) ;

  fruitPos.push_back(std::rand() % sizeGrid.at(0)) ;
  fruitPos.push_back(std::rand() % sizeGrid.at(1)) ;

  score = 0 ;
}

void draw()
{
  system("clear") ;
  for ( int x = -1 ; x < sizeGrid.at(0) + 1 ; x++ )
  {
    for ( int y = -1 ; y < sizeGrid.at(1) + 1 ; y++ )
    {
      if ( x == -1 or x == sizeGrid.at(0) )
      {
        std::cout << "#" ;
      }
      else if ( y == -1 )
      { 
        std::cout << "#" ;
      }
      else if ( y == sizeGrid.at(1) )
      {
        std::cout << "#" ;
      }
      else if ( x == pos.at(0) and y == pos.at(1) )
      {
        std::cout << "O" ;
      }
      else if ( x == fruitPos.at(0) and y == fruitPos.at(1) )
      {
        std::cout << "X" ;
      }
      else
      {
        std::cout << " " ;
      }
    }
    std::cout << std::endl ;
  }
}

void input()
{
  if ( _kbhit() )
  {
    switch ( getch() )
    {
      case KEY_Z :
      case KEY_z :
      case KEY_UP : 
        dir = DIRECTION::UP ;
        break ;

      case KEY_Q :
      case KEY_q :
      case KEY_LEFT : 
        dir = DIRECTION::LEFT ;
        break ;

      case KEY_S :
      case KEY_s :
      case KEY_DOWN :
        dir = DIRECTION::DOWN ;
        break ;

      case KEY_D :
      case KEY_d :
      case KEY_RIGHT :
        dir = DIRECTION::RIGHT ;
        break ;

      case KEY_X :
      case KEY_x :
      case ESC :
        gameOver = true ;
        break ;
    }
  }
}

void logic()
{

}


int main( int argc, char** argv )
{
  std::srand(time(nullptr)) ;

  setup() ;
  while ( not gameOver )
  {
    draw() ;
    input() ;
    logic() ;
  }

  return 0 ;
}