/************************************************
 * FILE: CarRatingService.hpp                   *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 04/19/2022                             *
 * PURPOSE: Represents a CarRatingService       *
 ************************************************/

#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

//include the necessary libraries 
#include "ListNode.hpp"
#include "CarRating.hpp"
#include <string>


//declare the CarRatingService class
class CarRatingService
{
    //delcare private instance variables
    private:
        //declare ListNode pointers for the head and tail
        ListNode *_head;
        ListNode *_tail;
        //declare _carCount to hold the number of cars in the CarRatingService
        int _carCount;

    //declare public methods
    public:
        //default contructor
        CarRatingService() : _head(NULL), _tail(NULL) {}

        //constructor to build a CarRatingService from and input stream
         CarRatingService(std::istream &input);

         //overloaded += with CarRating
         CarRatingService operator+=(const CarRating &cr);

         //overloaded += with CarRatingService
         CarRatingService operator+=(const CarRatingService &crs);

         //overloaded -= with CarRating
         CarRatingService operator-=(const CarRating &cr);

         //overloaded = with two CarRatingService objets
         CarRatingService operator=(const CarRatingService &crs);

         //overloaded << for a CarRatingService
         friend std::ostream& operator<<(std::ostream &os, const CarRatingService &crs);

        //returns a pointer to a list node which will not return a copy of the list node
        ListNode* findTail() const { return _tail; }

        //methods to find certain make, models, and years and print them out
        void printMake(const std::string &make);
        void printModel(const std::string &model);
        void printYear(int year);

        //number of car
        int numCars() { return _carCount; }

        //clear the service
        void clear();
        
};




#endif
