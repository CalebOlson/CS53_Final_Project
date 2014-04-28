//-----------------------------------------------------------------------------
//Programmer: Caleb Olson               Date: 4-19-14
//File: schoolyard.h                    Class: CS53 Section B
//Purpose: Header file for the schoolyard class.
//-----------------------------------------------------------------------------

#ifndef SCHOOLYARD_H
#define SCHOOLYARD_H

#include<iostream>

#include"classmate.h"

using namespace std;

/*---------- Constant Declarations ----------*/

//maximum size the schoolyard can be in any one direction
const short MAX_SCHOOLYARD_SIZE = 25;

//Percent of empty spaces filled with trash
const int PERCENT_TRASH = 10;

const char SCHOOL = 'S';  //a position with part of the school in it
const char DOOR = 'D';  //a position with the door in it
const char TRASH = 'T';  //a position with trash in it
const char EMPTY_SPACE = ' ';  //a position with nothing in it.


/*---------- Class Function Comments ----------*/

//schoolyard():
//a constructor that gives the schoolyard the desired size and calls 
//build_school() to populate it
//Pre: yard_size is no larger than MAX_SCHOOLYARD_SIZE and school_size is 
//smaller than yard_size.
//Post: build_school() is called and m_yard_size and m_school_size have valid 
//values.

//get_yard_size():
//returns the size of the schoolyard
//Pre: the schoolyard() constructor has been called for the calling object
//Post: the yard size is returned

//get_school_size():
//returns the size of the school
//Pre: the schoolyard() constructor has been called for the calling object
//Post: the school size is returned

//operator <<():
//overrides the << operator to correctly print a schoolyard to the screen
//Pre: the schoolyard() constructor has been called for the calling object
//Post: a correctly formatted schoolyard is printed to the screen.

//build_school():
//fills the schoolyard with empty space and then adds a school, a door, and
//trash
//Pre: the schoolyard() constructor has been called for the calling object
//Post: there is a school of size m_school_size, there is a door on the 
//bottom right of the school, the rest of the schoolyard is filled with empty
//space, and 10% of the empty space has trash in it 

/*---------- Class Declaration ----------*/

//Represents Ralph's schoolyard and all the things it contains using a 2D array
//of chars
class schoolyard
{
  public:
    
    schoolyard(const short yard_size, const short school_size);
    
    short get_yard_size()const;
    
    short get_school_size()const;
    
    friend ostream & operator << (ostream & os, const schoolyard 
                                  & my_yard);
    
  private:
    
    //represents the schoolyard as a 2D array of chars
    char m_schoolyard_map[MAX_SCHOOLYARD_SIZE][MAX_SCHOOLYARD_SIZE];
    short m_yard_size;  //The size of the schoolyard in one direction
    short m_school_size;  //size of the school in one direction
    
    
    void build_school();
    
};

#endif