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
    
  cout << "\n\nKEY: \nS = School \nD = Door \nT = Trash \nH = Hoover \nC = "
     << "Classmate" << endl << endl;
  cout << my_schoolyard << endl;
  
  //Keeps moving while both are not finished and the num moves is less than 10
  //the num moves is a placeholder to prevent infinite looping
  while(my_schoolyard.get_trash_count() != 0 && num_moves < 10)
  {
    classmate1.rand_move(my_schoolyard);
    classmate2.rand_move(my_schoolyard);
    if(num_moves < 10)
      cout << my_schoolyard << endl;
    num_moves++;
  }
  //Eventually will cout the winner
  cout << "The winner is ";
  
  /* Sudo Code:
  
  if(c1.isWinner)
    cout c1
  else
    cout c2
    
  */
  cout << "It took " << num_moves << " to win!" << endl;
  cout << "Goodbye!" << endl;
  return 0;
}
