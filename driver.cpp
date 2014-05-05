//-----------------------------------------------------------------------------
//Programmer: Caleb Olson and Sawyer McLane  Date: 5-05-14
//File: driver.cpp                           Class: CS53 Section B
//Purpose: Create and test objects of the classmate and schoolyard class'. 
//-----------------------------------------------------------------------------

#include"classmate.h"
#include"schoolyard.h"

using namespace std;

/*---------- Constant Declarations ----------*/

const int NUM_STEPS = 5;
const int SCHOOLYARD_SIZE = 13;
const int SCHOOL_SIZE = 9;
const int IQ = 60;
const string CLASSMATE_NAME = "Ralph";


/*---------- Main Function ----------*/

int main()
{
  srand(time(NULL));
  
  cout << "Testing all functions now!\n\n" << endl;
  
  //creates a schoolyard object
  schoolyard my_school(SCHOOLYARD_SIZE, SCHOOL_SIZE);
  
  //prints the schoolyard object
  cout << my_school << endl;
  
  cout << "\n" << endl;
  
  //prints info about the schoolyard object
  cout << "School Size: " << my_school.get_school_size() << endl;
  cout << "Schoolyard Size: " << my_school.get_yard_size() << endl;
  
  cout << "\n" << endl;
  
  //creates a classmate object
  classmate ralph(my_school, CLASSMATE_NAME);
  //tests the default in the classmate constructor
  classmate bob(my_school);
  
  //prints out the classmate objects
  cout << ralph << endl;
  cout << bob << endl;
  
  cout << "\n" << endl;
  
  //tests the place() function
  ralph.go_to_school(my_school);
  cout << ralph << endl;
  
  cout << "\n" << endl;
  
  //tests the set_IQ() function
  ralph.set_IQ(IQ);
  cout << ralph << endl;
  
  cout << "\n" << endl;
  
  //tests the get_IQ() function
  cout << "Ralph's IQ: " << ralph.get_IQ() << endl;
  
  cout << "\n" << endl;
  
  //tests the move() function
  for(int i = 0; i < NUM_STEPS; i++)
  {
    ralph.move();
    cout << ralph << endl;
  }
  
  cout << my_school << endl;
  return 0;
}