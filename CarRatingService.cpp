/************************************************
 * FILE: CarRatingService.cpp                   *
 * AUTHOR: Morgan Purcell                       *
 * DATE: 04/19/2022                             *
 * PURPOSE: Implements CarRatingService methods *
 ************************************************/

//include the necessary libraries 
#include "CarRatingService.hpp"

//declare the use of the standard namespace
using namespace std;


//constructor based on input stream
CarRatingService::CarRatingService(std::istream &input)
{
    //initialize _head and _tail = NULL
    _head = NULL;
    _tail = NULL;
    //initialize _carCount to 0
    _carCount=0;
  
    //declare an object of type CarRating
    CarRating cr;
    //read CarRating objects into the CarRatingService
    while(input >> cr)
    {
        this->operator+=(cr);
    }
}

//overloaded += operator which takes a CarRating object
CarRatingService
CarRatingService::operator+=(const CarRating &cr)
{
    //initialize a ListNode object to cr
    ListNode *nodeToAdd = new ListNode(cr);
    //initialize a ListNode object to _tail
    ListNode *tail = findTail();

    //if _head = NULL there are no nodes in the CarRatingService
    //add the new node by setting _head and _tail = to it and return the CarRatingService
    if(!_head)
    {
        _head = nodeToAdd;
        _tail = nodeToAdd;
        //update _carCount
        _carCount++;

        return *this;
    }

    //initialize a ListNode object to _head
    ListNode *curr;
    curr = _head;
    //while curr does not point to NULL
    while(curr)
    {
        //check if cr is = to the node in CarRatingService
        if(cr == curr->data())
        {
            //update the node in CarRatingService with cr's data using the overloaded += operator and return the CarRatingService
            curr->data() += cr.rating();
            return *this;
        }
        //if not, check the next node
        else
            curr = curr->next();
    }

    //add the new node to the end of the CarRatingService
    tail->next() = nodeToAdd;
    //update the tail
    _tail = nodeToAdd;
    //update _carCount
    _carCount++;

    //return the CarRatingService
    return *this;
}


//overloaded += operator which takes a CarRatingService object
CarRatingService 
CarRatingService::operator+=(const CarRatingService &crs)
{
    //initialize a list node pointer to _head
    ListNode *curr = crs._head;
    //while curr does not point to NULL
    while (curr)
    {
        //call the += operator on the implicit parameter and the current ListNode object
        operator+=(curr->data());
        //move the the next node in the list
        curr = curr->next();
    }
    //return the implicit parameter
    return *this;
}


//overloaded -= operator
CarRatingService 
CarRatingService::operator-=(const CarRating &cr)
{
    //if the list is empty, do nothing
    if(!_head)
    {
        return *this;
    }

    //if there's only one item in the list, clear the list
    if(_head == _tail)
    {
        this->clear();
        return *this;
    }


    //remove the head
    //initialize a ListNode object to _head
    ListNode *firstNode = _head;
    //if the first node == the CarRating Object
    if(firstNode->data() == cr)
    {
        //set _head to the second node in the list
        _head = _head->next();
        //set the first node pointer = NULL
        firstNode->next() = NULL;
        //return the implicit parameter
        return *this;
    }

    //initialize a ListNode object to _head
    ListNode *removeNext = _head;
    //while removeNext is not = NULL
    while(removeNext)
    {
        //set removeThis = removeNext's next node
        ListNode *removeThis = removeNext->next();

        //if removeNext = _tail the list was fully searched and the CarRating object was not found
        if(removeNext == _tail)
        {
            //putput a message saying the CarRating object is not in the list
            cout << "The car rating was not found in the list!" << endl;
            //return the implicit parameter
            return *this;
        }

        //if removeThis = the CarRating object
        if(removeThis->data() == cr)
        {
            //set removeNext's next = removeThis's next, remove removeThis from the list
            removeNext->next() = removeThis->next();
            //set removeThis's next = NULL
            removeThis->next() = NULL;
            //check if _tail was = to the list node that was removed and update the tail if necessary
            if(_tail == removeThis)
            {
                _tail = removeNext;
            }
            //return the implicit parameter
            return *this;
        }
        //check the next node
        else
            removeNext = removeNext->next();
    }

    //PROGRAM WON'T GET HERE
    cout << "The car rating was not found in the list!" << endl;
    return *this;
}


//overloaded = operator
CarRatingService 
CarRatingService::operator=(const CarRatingService &crs)
{
    //set the implicit parameters head and tail to Null so that the list is cleared out 
    this->_head = NULL;
    this->_tail = NULL;

    //initialize a list node pointer to the head of the CarRatingService to be copied from
    ListNode *curr = crs._head;
    //while curr does not point to NULL
    while (curr)
    {
        //call the += operator on the implicit parameter and the current ListNode object
        this->operator+=(curr->data());
        //move the the next node in the list
        curr = curr->next();
    }

    return *this;
}


//overloaded << which takes a CarRatingService object
std::ostream& operator<<(std::ostream &os, const CarRatingService &crs)
{
  //initialize a list node pointer to _head
  ListNode *curr = crs._head;

  //while the list node does not point to null
  while (curr)
    {
      //assign the output stream to the list node data
      os << curr->data() << "\n";
      //the list node pointer now points to the list nodes next part(the next node)
      curr = curr->next();
    }
    //return the output stream
    return os;
}


//clear method to clear the CarRatingService
void
CarRatingService::clear()
{
    //set the car count to 0
    _carCount = 0;
    //set _head and _tail to NULL
    _head = NULL;
    _tail = NULL;
}


//printMake method to check for all instinces of a CarRating make in a list
void 
CarRatingService::printMake(const std::string &make)
{
    //initialize a ListNode pointer to _head
    ListNode *curr = _head;
    //while curr is not equal to NULL
    while(curr)
    {
        //if the make of the CarRating object in curr = make
        if(curr->data().make() == make)
        {
            //output the CarRating object
            cout << curr->data() << endl;;
        }
        //set curr = to curr's next to check the next node in the list
        curr=curr->next();
    }
}


//printModel method to check for all instinces of a CarRating model in a list
void 
CarRatingService::printModel(const std::string &model)
{
    //initialize a ListNode pointer to _head
    ListNode *curr = _head;
    //while curr is not equal to NULL
    while(curr)
    {
        //if the make of the CarRating object in curr = make
        if(curr->data().model() == model)
        {
            //output the CarRating object
            cout << curr->data() << endl;;
        }
        //set curr = to curr's next to check the next node in the list
        curr=curr->next();
    }
}

//printYear method to check for all instinces of a CarRating year in a list
void 
CarRatingService::printYear(int year)
{
    //initialize a ListNode pointer to _head
    ListNode *curr = _head;
    //while curr is not equal to NULL
    while(curr)
    {
        //if the make of the CarRating object in curr = make
        if(curr->data().year() == year)
        {
            //output the CarRating object
            cout << curr->data() << endl;;
        }
        //set curr = to curr's next to check the next node in the list
        curr=curr->next();
    }
}
