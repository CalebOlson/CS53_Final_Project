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


/*---------- Struct Declarations ----------*/



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
//defaults to DEFAULT_NAME, 0 trash, and an ungraded project.
//Pre: none
//Post: The calling object has a value for m_name, m_num_trash,m_graded,
//and m_IQ

//go_to_school():
//gives the calling object a location value on the array
//Pre: the classmate() constructor has been called for the calling object
//Post: m_position represents a random point on the array, m_space_type has
//the value of EMPTY_SPACE.

//set_IQ():
//sets the IQ of the calling object
//Pre: the classmate() constructor has been called for the calling object.
//IQ is greater than 0 and less than 250
//Post: the IQ of the calling object is set to IQ if it is greater than 0 and
//less than 250. Otherwise a variable representing an error is returned

//get_IQ():
//returns the IQ of the calling object
//Pre: the classmate() constructor has been called for the calling object
//Post: gets the calling object's IQ

//grade_project():
//grades the classmates project and removes it from the board
//Pre: my_schoolyard has been initialized, m_pocket is of size POCKET_SIZE 
//Post: m_grade is the classmates grade, m_graded is true, the C representing
//the classmate is removed from the schoolyard

//get_grade():
//returns the classmates grade
//Pre: m_grade has a valid value
//Post: returns the classmates grade, m_grade

//isGraded():
//returns if the student's project has been graded or not
//Pre: none
//Post: the value of m_graded is returned

//valid_move():
//checks if the given move is valid for the calling classmate
//Pre: the schoolyard constructor has been called for my_schoolyard, the
//classmate constructor has been called for the calling classmate.
//Post: returns weather or not the move is valid

//rand_move():
//moves the calling object one space in a random direction
//Pre: the classmate() constructor has been called for the calling object, 
//the schoolyard constructor has been called for my_schoolyard
//Post: m_position of the calling object has been shifted one space in a random
//direction without going outside the array and the C representing the calling
//object has been moved to the respective place on my_schoolyard.

//move_to_teacher():
//moves the calling object towards the teacher if possible
//Pre: the classmate constructor has been called for the calling object, the 
//schoolyard constructor has been called for my_schoolyard
//Post: m_position of the calling object has been shifted to an adjacent cell
//on the schoolyard. if possible it is in the direction of the teacher

//move_to_door():
//moves the calling object towards the door if possible
//Pre: the classmate constructor has been called for the calling object, the 
//schoolyard constructor has been called for my_schoolyard
//Post: m_position of the calling object has been shifted to an adjacent cell
//on the schoolyard. if possible it is in the direction of the door

//move():
//Moves the calling object one space on the board or has the object turn in 
//its project
//Pre: the classmate constructor has been called for the calling object, the 
//schoolyard constructor has been called for my_schoolyard
//Post: The classmate is either moved one space on my_schoolyard or its project
//is graded.

//get_trash():
//grabs trash from an adjacent cell
//Pre: The x and y coordinates passed are valid
//Post: Trash has been added to the classmate's pocket if there is room 
//and the cell is cleared.

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
    
    double get_grade()const;
    
    void grade_project(schoolyard & my_schoolyard);
    
    bool isGraded()const;
    
    bool valid_move(const schoolyard & my_schoolyard, const int  
                               X_val, const int Y_val)const;
    
    void rand_move(schoolyard & my_schoolyard);
    
    void move_to_teacher(schoolyard & my_schoolyard);
    
    void move_to_door(schoolyard & my_schoolyard);
    
    void move(schoolyard & my_schoolyard);
    
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
    
    bool m_graded;  //True if the classmate's project has been graded
    double m_grade;  //The classmate's grade for its assignment
    
};

#endif
