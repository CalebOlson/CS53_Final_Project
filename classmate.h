//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 5-05-14
//File: classmate.h                          Class: CS53 Section B
//Purpose: Header file for the classmate class. 
//-----------------------------------------------------------------------------

#ifndef CLASSMATE_H
#define CLASSMATE_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>

#include"schoolyard.h"

using namespace std;

/*---------- Constant Declarations ----------*/

const string TRASH_DATA_FILE = "trash.dat";
const string DEFAULT_NAME = "Bob";
const short MAX_IQ = 70;
const short MIN_IQ = 50;
const short NUM_MOVE_DIRECTIONS = 4;
const short POCKET_SIZE = 10;

/*---------- Forward Declarations ----------*/

class schoolyard; //Allows passage of a Schoolyard class in the program. 

/*---------- Struct Declarations ----------*/

//Represents a point in the array. Holds an x and y value for horizontal and
//vertical position, respectively.
struct point
{
  short m_val_X;  //the x position of the point
  short m_val_Y;  //the y position of the point
};


//Represents a piece of trash. Contains a name and the value of the trash when
//used in a project.
struct Trash
{
  string m_name;  //The trash's name
  int m_value;   //The value of the trash when used in a project
  
  //constructor that assigns the trash object a certain type of trash chosen
  //randomly from a file.
  //Pre: there must be a fine in the parent directory of classmate.h that
  //contains values and names for trash objects. 
  //The first line in the file should have the number of types of trash in the
  //file.
  //Post: m_name and m_value have been assigned the values from a type of trash
  //in the data file.
  Trash();
};


/*---------- Class Function Comments ----------*/

//classmate():
//constructor that makes a classmate object with a random IQ, a name that
//defaults to DEFAULT_NAME and calls the place() function for the classmate
//Pre: none
//Post: The calling object has a value for m_name, m_position, and m_IQ

//go_to_school(): 
//gives the calling classmate a location on the yard
//Pre: the yard has been initialized 
//Post: m_position represents a random point on the yard

//go_to_school():
//gives the calling object a location value on the array
//Pre: the classmate() constructor has been called for the calling object
//Post: m_position represents a random point on the array, m_space_type has
//the value of EMPTY_SPACE.

//set_IQ():
//sets the IQ of the calling object
//Pre: the classmate() constructor has been called for the calling object.
//IQ is greater than 0
//Post: the IQ of the calling object is set to IQ if it is greater than 0
//Otherwise an variable representing an error is returned

//get_IQ():
//returns the IQ of the calling object
//Pre: the classmate() constructor has been called for the calling object
//Post: gets the calling object's IQ

//rand_move():
//moves the calling object one space in a random direction
//Pre: the classmate() constructor has been called for the calling object
//Post: m_position of the calling object has been shifted one space in a random
//direction without going outside the array

//smart_move():
//moves the calling object towards a trash object
//Pre: the classmate constructor has been called for the calling object
//Post: m_position of the calling object has been shifted to an adjacent trash
//object.

//get_trash():
//grabs trash from an adjacent cell
//Pre: The x and y coordinates passed are valid
//Post: Trash has been added to the classmate's pocket, and the cell is cleared.

//operator <<():
//Overloads the << operator to print out a classmate
//Pre: the classmate() constructor has been called for the calling object
//Post: a correctly formatted classmate is printed to the screen


/*---------- Class Declaration ----------*/

//represents one of Ralph's classmates and contains their name, position, and
//IQ along with functions to modify them.
class classmate
{
  public:
    
    classmate(const string name = DEFAULT_NAME);
    
    void go_to_school(schoolyard & my_schoolyard);
    
    bool set_IQ(const short IQ);
    
    short get_IQ()const;
    
    double get_score()const;
    
    bool valid_move(const schoolyard & my_schoolyard, const point & my_point
                    )const;
    
    void rand_move(schoolyard & my_schoolyard);
    
    void smart_move(schoolyard & my_schoolyard);
    
    bool get_trash(schoolyard & my_schoolyard, const int x, const int y);
    
    friend ostream & operator << (ostream & os, const classmate & kid);
    
  private:
    
    string m_name;  //The name of the classmate
    short m_IQ;  //the intelligence quotient of the classmate
    
    point m_position;  //the position of the classmate on the schoolyard
    //the type of space the character is on (trash, door, empty space, ect.)
    char m_space_type;
    
    Trash m_pocket[POCKET_SIZE];  //the size of the classmate's pocket
    short m_num_trash;  //number of pieces of trash in the classmate's pocket
    short m_trash_value; //a running value of all the trash in the classmate's pocket
    
    bool m_graded;  //True if the classmate's project has been graded
    short m_grade;  //The classmate's grade for its assignment
    
};

#endif
