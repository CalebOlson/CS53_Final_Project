//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 5-05-14
//File: classmate.cpp                        Class: CS53 Section B
//Purpose: Define functions for use with the classmate class. 
//-----------------------------------------------------------------------------

#include"classmate.h"

using namespace std;

/*---------- Function Definitions ----------*/

/*----- Member Functions -----*/

classmate::classmate(const string name)
{
  //assign a name to this classmate
  m_name = name;
  
  //assign an IQ to this classmate
  set_IQ(rand()%(MAX_IQ - MIN_IQ + 1) + MIN_IQ);
  
  m_num_trash = 0;  //sets the amount of trash in the classmate's pocket to 0.
  
  m_trash_value = 0;
  
  m_graded = false;
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
    myX = my_schoolyard.get_school_size() + 
          (rand()%(my_schoolyard.get_yard_size() - 
          my_schoolyard.get_school_size()));
    myY = my_schoolyard.get_school_size() + 
          (rand()%(my_schoolyard.get_yard_size() - 
          my_schoolyard.get_school_size()));
          
    if(my_schoolyard.get_cell(myX, myY) == EMPTY_SPACE)
    {
      my_schoolyard.set_cell(CLASSMATE, myX, myY);
      m_position.m_val_X = myX;
      m_position.m_val_Y = myY;
      done = true;
    }
  }
  
  m_space_type = EMPTY_SPACE;
  return;
}


bool classmate::set_IQ(const short IQ)
{
  bool is_set = false;  //is true if the IQ is valid
  
  if(IQ > 0 && IQ < 250)
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


double classmate::get_score()
{
  m_grade = static_cast <double> (m_trash_value) / m_IQ;
  return m_grade;
}


bool classmate::isGraded()const
{
  return m_graded;
}


bool classmate::valid_move(const schoolyard & my_schoolyard, const int X_val, 
                           const int Y_val)const
{
  //is true if the the position (X_val, Y_val) is a valid place to move to.
  bool is_valid = false; 
  
  //checks if the move will take the classmate outside the schoolyard
  if(X_val < my_schoolyard.get_yard_size() && X_val >= 0 && Y_val < 
     my_schoolyard.get_yard_size() && Y_val >= 0)
  {
    //Checks if the classmate is trying to move onto another classmate or the
    //teacher
    if(my_schoolyard.get_cell(X_val, Y_val) != CLASSMATE && my_schoolyard.get_cell(X_val, Y_val) != HOOVER)
    {
      //checks if the classmate tries to go through a wall into the school
      if((m_space_type == EMPTY_SPACE) && (my_schoolyard.get_cell(X_val, Y_val)
         != SCHOOL))
      {
        is_valid = true;
      }
      
      //checks if the classmate tries to go through a wall out of the school
      if((m_space_type == SCHOOL) && (my_schoolyard.get_cell(X_val, Y_val)
         != EMPTY_SPACE))
      {
        is_valid = true;
      }
      
      //allows the classmate to exit and enter the school through the door.
      if(m_space_type == DOOR)
      {
        is_valid = true;
      }
    }
    
  }
  
  return is_valid;
}


void classmate::rand_move(schoolyard & my_schoolyard)
{
  //true if the classmate has moved this time
  bool has_moved= false;
  
  my_schoolyard.set_cell(m_space_type, m_position.m_val_X, 
                         m_position.m_val_Y);
  

 
  while(!has_moved)  //loops until the classmate makes a move
  {
    short move_direction = rand()%(NUM_MOVE_DIRECTIONS + 1);
  
    if(move_direction == 1 && valid_move(my_schoolyard, m_position.m_val_X - 1,
       m_position.m_val_Y))
    {
      get_trash(my_schoolyard, m_position.m_val_X-1, m_position.m_val_Y);
      m_position.m_val_X--;
      has_moved = true;
    }
    else if(move_direction == 2 && valid_move(my_schoolyard, 
            m_position.m_val_X, m_position.m_val_Y-1))
    {
      get_trash(my_schoolyard,m_position.m_val_X, m_position.m_val_Y - 1);
      m_position.m_val_Y--;
      has_moved = true;
    }
    else if(move_direction == 3 && valid_move(my_schoolyard, m_position.m_val_X
            + 1, m_position.m_val_Y))
    {
      get_trash(my_schoolyard,m_position.m_val_X+1, m_position.m_val_Y);
      m_position.m_val_X++;
      has_moved = true;
    }
    else if(move_direction == 4 && valid_move(my_schoolyard, 
            m_position.m_val_X, m_position.m_val_Y + 1))
    {
      get_trash(my_schoolyard,m_position.m_val_X, m_position.m_val_Y+1);
      m_position.m_val_Y++;
      has_moved = true;
    }
  }
 
  m_space_type = my_schoolyard.get_cell(m_position.m_val_X, m_position.m_val_Y);

  my_schoolyard.set_cell(CLASSMATE, m_position.m_val_X, m_position.m_val_Y);
  return;
}

void classmate::move_to_teacher(schoolyard & my_schoolyard)
{
  char value_to_place;
  
  if(m_position.m_val_X == my_schoolyard.get_school_size()-1 && m_position.m_val_Y == my_schoolyard.get_school_size()-1)
    value_to_place = DOOR;
  else
    value_to_place = SCHOOL;
  
  if(m_position.m_val_X < my_schoolyard.get_teach().m_val_X && valid_move(my_schoolyard,m_position.m_val_X+1,m_position.m_val_Y))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X+1,m_position.m_val_Y);
    my_schoolyard.set_cell(value_to_place,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_X++;
  }
  else if(m_position.m_val_X > my_schoolyard.get_teach().m_val_X && valid_move(my_schoolyard,m_position.m_val_X-1,m_position.m_val_Y))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X-1,m_position.m_val_Y);
    my_schoolyard.set_cell(value_to_place,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_X--;
  }
  else if(m_position.m_val_Y < my_schoolyard.get_teach().m_val_Y&& valid_move(my_schoolyard,m_position.m_val_X,m_position.m_val_Y+1))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X,m_position.m_val_Y+1);
    my_schoolyard.set_cell(value_to_place,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_Y++;
  }
  else if(m_position.m_val_Y > my_schoolyard.get_teach().m_val_Y && valid_move(my_schoolyard,m_position.m_val_X,m_position.m_val_Y-1))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X,m_position.m_val_Y-1);
    my_schoolyard.set_cell(value_to_place,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_Y--;
  }
  return;
}

void classmate::move_to_door(schoolyard & my_schoolyard)
{
  if(m_position.m_val_X < my_schoolyard.get_school_size() - 1 && valid_move(my_schoolyard,m_position.m_val_X+1,m_position.m_val_Y))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X+1,m_position.m_val_Y);
    my_schoolyard.set_cell(EMPTY_SPACE,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_X++;
  }
  else if(m_position.m_val_X > my_schoolyard.get_school_size() - 1 && valid_move(my_schoolyard,m_position.m_val_X-1,m_position.m_val_Y))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X-1,m_position.m_val_Y);
    my_schoolyard.set_cell(EMPTY_SPACE,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_X--;
  }
  else if(m_position.m_val_Y < my_schoolyard.get_school_size() - 1 && valid_move(my_schoolyard,m_position.m_val_X,m_position.m_val_Y+1))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X,m_position.m_val_Y+1);
    my_schoolyard.set_cell(EMPTY_SPACE,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_Y++;
  }
  else if(m_position.m_val_Y > my_schoolyard.get_school_size() - 1 && valid_move(my_schoolyard,m_position.m_val_X,m_position.m_val_Y-1))
  {
    my_schoolyard.set_cell(CLASSMATE,m_position.m_val_X,m_position.m_val_Y-1);
    my_schoolyard.set_cell(EMPTY_SPACE,m_position.m_val_X,m_position.m_val_Y);
    m_position.m_val_Y--;
  }
  return;
}

void classmate::move(schoolyard & my_schoolyard)
{
  if(my_schoolyard.get_trash_count() > 0)
    rand_move(my_schoolyard);
  else if(m_position.m_val_X > my_schoolyard.get_school_size()-1 || m_position.m_val_Y > my_schoolyard.get_school_size()-1)
    move_to_door(my_schoolyard);
  else
    move_to_teacher(my_schoolyard);
  return;
}


bool classmate::get_trash(schoolyard & my_schoolyard, const int x, const int y)
{
  bool found = false;
  if(my_schoolyard.get_cell(x,y) == TRASH)
    {
      Trash t;
      if(m_num_trash < POCKET_SIZE)
      {
        if(t.m_name == "glue")
          m_IQ -= 2;
        else
        {
          m_pocket[m_num_trash] = t;
          m_num_trash++;
          m_trash_value += t.m_value;
        }
      }
      my_schoolyard.pick_up_trash();
      my_schoolyard.set_cell(EMPTY_SPACE, x, y);
      found = true;
      cout << m_name << " got " << t.m_name << endl << endl;
    }
  return found;
}

/*----- Friend Functions -----*/

ostream & operator << (ostream & os, const classmate & kid)
{
  os << kid.m_name << ", who has iq " << kid.m_IQ << " and is at ("
     << kid.m_position.m_val_X << ", " << kid.m_position.m_val_Y << ")";
  return os;
}


/*----- Struct Function Definitions -----*/

Trash::Trash()
{
  int num_types_trash;  //number of different types of trash
  int type_trash;  //The position in the file of the chosen type of trash
  
  ifstream fin;  //creates a new file input stream
  
  fin.open(TRASH_DATA_FILE.c_str());  //opens the trash data file
  
  //gets the number of types of trash
  fin >> num_types_trash;
  
  //randomly chooses a position of a type of trash in the file
  type_trash = rand()%(num_types_trash-1)+1;
  
  fin.ignore(5, '\n');
  
  for(int i = 0; i < type_trash; i++)
  {
    fin >> m_value;
    
    fin.ignore(1, ' ');
    
    getline(fin, m_name);
  }
}
