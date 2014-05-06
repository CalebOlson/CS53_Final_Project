//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 5-05-14
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
  
  m_trash_count = ((m_yard_size * m_yard_size) - 
                   (m_school_size * m_school_size)) * 
                   (static_cast<float>(PERCENT_TRASH) / 100);
  
  build_school();
  
  //Place hoover in a random place in the building.
  set_cell(HOOVER, rand()%m_school_size-1, rand()%m_school_size-1);
}


short schoolyard::get_yard_size()const
{
  return m_yard_size;
}


short schoolyard::get_school_size()const
{
  return m_school_size;
}


short schoolyard::get_trash_count()const
{
  return m_trash_count;
}


void schoolyard::pick_up_trash()
{
  m_trash_count--;
  return;
}


char schoolyard::get_cell(const short x_val, const short y_val)const
{
  return m_schoolyard_map[x_val][y_val];
}

bool schoolyard::set_cell(const char cell_value, const short x_val, const short
                          y_val)
{
  bool isSet = false;
  if(x_val >= 0 && x_val < MAX_SCHOOLYARD_SIZE && y_val >= 0 && y_val <
  MAX_SCHOOLYARD_SIZE)
  {
    if(m_schoolyard_map[x_val][y_val] == TRASH && cell_value != TRASH)
    {
      m_trash_count--;
    }
    m_schoolyard_map[x_val][y_val] = cell_value;
    isSet = true;
  }
  return isSet;
}


void schoolyard::build_school()
{
  //number of pieces of trash that should be placed in the schoolyard
  short trash_count = get_trash_count();
  
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
  while(trash_count > 0)
  {
    trash_X = rand()%(m_yard_size);
    trash_Y = rand()%(m_yard_size);
    
    if(m_schoolyard_map[trash_X][trash_Y] == ' ')
    {
      m_schoolyard_map[trash_X][trash_Y] = TRASH;
      trash_count--;
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
  return os;
}
