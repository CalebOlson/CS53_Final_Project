//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 4-28-14
//File: schoolyard.cpp                       Class: CS53 Section B
//Purpose: Function definitions for the schoolyard class.
//-----------------------------------------------------------------------------

#include"schoolyard.h"

using namespace std;

/*---------- Function Definitions ----------*/

/*----- Member Functions -----*/

schoolyard::schoolyard(const short yard_size, const short school_size)
{
  //check to ensure program will not run off of the arrays
  if(yard_size > MAX_SCHOOLYARD_SIZE)
  {
    cout << "ERROR: The schoolyard size is too large!" << endl;
    exit(5);
  }
  //check to make sure there is room in the schoolyard for the classmates
  if(school_size >= yard_size)
  {
    cout << "ERROR: The School is too big for the schoolyard!" << endl;
    exit(6);
  }
  
  m_yard_size = yard_size;
  m_school_size = school_size;
  
  build_school();
}


short schoolyard::get_yard_size()const
{
  return m_yard_size;
}


short schoolyard::get_school_size()const
{
  return m_school_size;
}


void schoolyard::build_school()
{
  //number of pieces of trash that should be placed in the schoolyard
  int num_pieces_trash = ((m_yard_size * m_yard_size) - 
                         (m_school_size * m_school_size)) * 
                         (static_cast<float>(PERCENT_TRASH) / 100);
  
  //stores the x and y coordinates of the piece of trash
  int trash_X, trash_Y;
  
  //builds the school and fills the schoolyard with empty spaces
  for(int y = 0; y < m_yard_size; y++)
  {
    for(int x = 0; x < m_yard_size; x++)
    {
      if(x < m_school_size && y < m_school_size)
      {
        if(x == (m_school_size - 1) && y == (m_school_size - 1))
          m_schoolyard_map[x][y] = DOOR;
        else
          m_schoolyard_map[x][y] = SCHOOL;
      }
      else
        m_schoolyard_map[x][y] = EMPTY_SPACE;
    }
  }
  
  //places the trash
  while(num_pieces_trash > 0)
  {
    trash_X = rand()%(m_yard_size);
    trash_Y = rand()%(m_yard_size);
    
    if(m_schoolyard_map[trash_X][trash_Y] == ' ')
    {
      m_schoolyard_map[trash_X][trash_Y] = TRASH;
      num_pieces_trash--;
    }
  }
  
  return;
}


/*----- Friend Functions -----*/

ostream & operator << (ostream & os, const schoolyard & my_yard)
{
  for(int i = 0; i < my_yard.m_yard_size+2; i++)
    os << "*";
  
  os << "\n";
  
  for(int y = 0; y < my_yard.m_yard_size; y++)
  {
    os << "*";
    for(int x = 0; x < my_yard.m_yard_size; x++)
    {
      os << my_yard.m_schoolyard_map[x][y];
    }
    os << "*\n";
  }
  
  for(int i = 0; i < my_yard.m_yard_size+2; i++)
    os << "*";
  
  os << "\n\nKEY: \nS = School \nD = Door \nT = Trash";
  return os;
}
