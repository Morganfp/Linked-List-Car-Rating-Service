// tests if our program can use the += operator to add a CarRatingService to an empty CarRatingService
// also tests if our program can use the += operator to add multiple variatons of the same car to an empty CarRatingService

#include <fstream>
#include <iostream>

#include "CarRating.hpp"
#include "CarRatingService.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile;

  cout << "\nThis test assumes that input3.txt exists " 
       << "in the current folder." << endl;

  ifile.open("input3.txt");
  //construct an old Car Rating Service
  CarRatingService oldCRS(ifile);
  ifile.close();

  //construct a new Car Rating Service
  CarRatingService newCRS;

  cout << "==== Contents of oldCRS (input3.txt) ====" << endl;
  cout << oldCRS << endl << endl; 

  cout << "==== Contents of newCRS (Should be empty) ====" << endl;
  cout << newCRS << endl << endl; 

  //add all the Car Ratings in oldCRS to newCRS
  newCRS += oldCRS;

  cout << "==== Contents of newCRS after adding oldCRS (input3.txt) ====" << endl;
  cout << newCRS << endl << endl;

  cout << "==== Contents of oldCRS (input3.txt) ====" << endl;
  cout << oldCRS << endl << endl; 

  //clear the old Car Rating Service
  cout << "Now clearing the service ...." << endl;
  oldCRS.clear();

  cout << "==== Contents of oldCRS (Should be empty)====" << endl;
  cout << oldCRS << endl << endl;

  //The old Car Rating Service is back open, add some Vintage Car Ratings to it
  cout << "==== Contents of oldCRS ratings after adding 5 Car Ratings ====" << endl;
  CarRating am1("Aston", "Martin", 1964);
  am1+=3;
  oldCRS+=am1;

  CarRating am2("Aston", "Martin", 1964);
  am2+=4;
  oldCRS+=am2;

  CarRating am3("Aston", "Martin", 1964);
  am3+=3;
  oldCRS+=am3;

  CarRating am4("Aston", "Martin", 1964);
  am4+=4;
  oldCRS+=am4;

  CarRating am5("Aston", "Martin", 1964);
  am5+=2;
  oldCRS+=am5;

  cout << oldCRS << endl << endl;


  return 0;
}
