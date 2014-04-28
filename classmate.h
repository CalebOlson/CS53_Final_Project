//-----------------------------------------------------------------------------
//Programmer: Caleb Olson               Date: 4-19-14
//File: classmate.h                     Class: CS53 Section B
//Purpose: Header file for the classmate class.
//-----------------------------------------------------------------------------

#ifndef CLASSMATE_H
#define CLASSMATE_H

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#include"schoolyard.h"

using namespace std;

/*---------- Constant Declarations ----------*/

const string DEFAULT_NAME = "Bob";
const short MAX_IQ = 70;
const short MIN_IQ = 50;
const short NUM_MOVE_DIRECTIONS = 4;


/*---------- Struct Declarations ----------*/

//Represents a point in the array. Holds an x and y value for horizontal and
//vertical position, respectively.
struct point
{
  short m_val_X;  //the x position of the point
  short m_val_Y;  //the y position of the point
};


/*---------- Class Function Comments ----------*/

//classmate():
//constructor that makes a classmate object with a random IQ, a name that
//defaults to DEFAULT_NAME and calls the place() function for the classmate
//Pre: none
//Post: The calling object has a value for m_name, m_position, and m_IQ

//place():
//gives the calling object a location value on the array
//Pre: the classmate() constructor has been called for the calling object
//Post: m_position represents a random point on the array

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

//move():
//moves the calling object one space in a random direction
//Pre: the classmate() constructor has been called for the calling object
//Post: m_position of the calling object has been shifted one space in a random
//direction without going outside the array

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
    
    void place();
    
    bool set_IQ(const short IQ);
    
    short get_IQ()const;
    
    void move();
    
    friend ostream & operator << (ostream & os, const classmate & kid);
    
  private:
    
    string m_name;  //The name of the classmate
    point m_position;  //the position of the classmate on the schoolyard
    short m_IQ;  //the intelligence quotient of the classmate
    
};

#endif