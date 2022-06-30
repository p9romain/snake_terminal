#include <iostream>
#include <vector>
#include <conio.h>

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
    switch ( _getch() )
    {
      case 'z' : 
        dir = DIRECTION::UP ;
        break ;

      case 'q' : 
        dir = DIRECTION::LEFT ;
        break ;

      case 's' : 
        dir = DIRECTION::DOWN ;
        break ;

      case 'd' : 
        dir = DIRECTION::LEFT ;
        break ;

      case ''
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