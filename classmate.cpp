//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 5-05-14
//File: classmate.cpp                        Class: CS53 Section B
//Purpose: Define functions for use with the classmate class. 
//-----------------------------------------------------------------------------

#include"classmate.h"

using namespace std;

/*---------- Function Definitions ----------*/

/*----- Member Functions -----*/

classmate::classmate(schoolyard & yard, const string name)
{
  //assign a name to this classmate
  m_name = name;
  
  //assign an IQ to this classmate
  set_IQ(rand()%(MAX_IQ - MIN_IQ + 1) + MIN_IQ);
  
  go_to_school(yard);
}

  
void classmate::go_to_school(schoolyard & my_schoolyard)
{
  /* 
    The flow of this function should be as follows:
      1. Generates a random x and y value that is inside the schoolyard
      but outside the building.
      2. If the position is not occupied (i.e blank), insert the classmate.
      Else, regenerate a spot.
      
  */
  short myX, myY;
  bool done = false; 
  while(!done)
  {
    myX = my_schoolyard.get_school_size() + (rand()%(my_schoolyard.get_yard_size() - 
      my_schoolyard.get_school_size()));
    myY = my_schoolyard.get_school_size() + (rand()%(my_schoolyard.get_yard_size() - 
      my_schoolyard.get_school_size()));
    if(my_schoolyard.get_cell(myX, myY) == EMPTY_SPACE)
    {
      my_schoolyard.set_cell(CLASSMATE, myX, myY);
      m_position.m_val_X = myX;
      m_position.m_val_Y = myY;
      done = true;
    }
  }
  return;
}


bool classmate::set_IQ(const short IQ)
{
  bool is_set = false;  //is true if the IQ is valid
  
  if(IQ > 0)
  {
    m_IQ = IQ;
    is_set = true;
  }
  return is_set;
}


short classmate::get_IQ()const
{
  return m_IQ;
}


void classmate::move()
{
  //true if the move will not take the classmate outside the array
  bool valid_move= false;
  
  while(!valid_move)  //ensures move is valid before making it
  {
    short move_direction = rand()%(NUM_MOVE_DIRECTIONS + 1);
  
    if(move_direction == 1 && m_position.m_val_X > 0)
    {
      m_position.m_val_X--;
      valid_move = true;
    }
    else if(move_direction == 2 && m_position.m_val_Y > 0)
    {
      m_position.m_val_Y--;
      valid_move = true;
    }
    else if(move_direction == 3 && m_position.m_val_X < MAX_SCHOOLYARD_SIZE-1)
    {
      m_position.m_val_X++;
      valid_move = true;
    }
    else if(move_direction == 4 && m_position.m_val_Y < MAX_SCHOOLYARD_SIZE-1)
    {
      m_position.m_val_Y++;
      valid_move = true;
    }
  }
  return;
}


/*----- Friend Functions -----*/

ostream & operator << (ostream & os, const classmate & kid)
{
  os << kid.m_name << " has iq " << kid.m_IQ << " and is at ("
     << kid.m_position.m_val_X << ", " << kid.m_position.m_val_Y << ").";
  return os;
}