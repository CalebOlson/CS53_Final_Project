//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 5-05-14
//File: driver.cpp                           Class: CS53 Section B
//Purpose: Create and test objects of the classmate and schoolyard class'. 
//-----------------------------------------------------------------------------

#include"classmate.h"
#include"schoolyard.h"

using namespace std;

/*---------- Constant Declarations ----------*/

const int SCHOOLYARD_SIZE = 20;
const int SCHOOL_SIZE = 5;
const string CLASSMATE1_NAME = "Ralph";
const string CLASSMATE2_NAME = "A Possum";


/*---------- Main Function ----------*/

int main()
{
  /*----- Variable Declarations -----*/
  
  int num_moves = 0;  //number of moves the simulation has been running
  
  //true if the respective classmate has turned in its project
  bool classmate1_finished = false, classmate2_finished = false;
  
  
  /*----- Program Execution -----*/
  
  srand(time(NULL));  //seeds the random number generator
  
  //creates a schoolyard object
  schoolyard my_schoolyard(SCHOOLYARD_SIZE, SCHOOL_SIZE);
  
  //create the two classmates
  classmate classmate1(CLASSMATE1_NAME);
  classmate classmate2(CLASSMATE2_NAME);
  
  //place the students in the schoolyard
  classmate1.go_to_school(my_schoolyard);
  classmate2.go_to_school(my_schoolyard);
  
  //print out the schoolyard
  cout << my_schoolyard << endl;
  
  while(!classmate1_finished && !classmate2_finished && num_moves < 100)
  {
    classmate1.move();
    classmate2.move();
    
    cout << my_schoolyard << endl;
    
    num_moves++;
  }
  
  cout << "The winner is " << endl;
  
  return 0;
}