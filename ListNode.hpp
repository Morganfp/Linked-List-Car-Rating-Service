/************************************************
 * FILE: ListNode.hpp                           *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 04/19/2022                             *
 * PURPOSE: Represents a list node              *
 ************************************************/

#ifndef _LIST_NODE_HPP_
#define _LIST_NODE_HPP_

//include the necessary libraries
#include "CarRating.hpp"


//declare the ListNode class
class ListNode
{
    //delcare private instance variables
    private:
        CarRating _data;
        ListNode *_next;

    //declare public methods
    public:
        //default constructor
        ListNode(): _data(), _next(NULL) {}

        //constrctor which takes a CarRating argumment and sets _data to that argument
        //_next is set to NULL
        ListNode(const CarRating &cr): _data(cr), _next(NULL) {}

        //accessor methods for _data and _next
        CarRating& data() { return _data; }
        ListNode*& next() { return _next; }
};


#endif
