/************************************************
 * FILE: CarRating.cpp                          *
 * AUTHOR: Dr. Blythe                           *
 * DATE: 2/2022                                 *
 * PURPOSE: Implements CarRating class          *
 ************************************************/
#include "CarRating.hpp"
using namespace std;
double
CarRating::addNewRating(int rating)
{
  // if the rating is invalid, give a message indicating such and
  // just return the current rating. 
  if (rating<1 || rating>4)
    {
      cerr << "Error: rating value must be 1, 2, 3, or 4 ("
   << rating << " is invalid)" << endl;
      return _rating;
    }
  // a bit of math here to update the rating value. Ask Dr. Blythe if
  //  you do not understand this math!
  _rating = (_numRatings * _rating + rating)/(_numRatings+1);
  _numRatings++;
  return _rating; 
}
bool
CarRating::operator==(const CarRating &other) const
{
  // remember that == doesnt care about the actual rating values, just the
  // car make, model and year. 
  return _year == other._year &&
    _model == other._model &&
    _make == other._make;
}
ostream&
CarRating::print(ostream &os) const
{
  os << _year << " " << _make << " " << _model
     << " " << _rating << " " << _numRatings << "";
  return os;
}
// overloaded output operator ... just use the above print method!
ostream& operator<< (ostream &os, const CarRating& cr)
{
  return cr.print(os);
}
//overloaded input operator ... yep, it's as simple as it looks!
istream& operator>> (istream &is, CarRating& cr)
{
  is >> cr._year;
  is >> cr._make;
  is >> cr._model;
  is >> cr._rating;
  is >> cr._numRatings;
  return is;
}
