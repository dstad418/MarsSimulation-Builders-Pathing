#include "linkedList.h"
#include "structuretype.h"

// NO OUTPUT ALLOWED FOR THIS CLASS



/* TESTER TO SEE WHY MY REMOVE FUNCTION IS EFFED
#include<iostream>
using namespace std;
*/


// Constructor w/ member initializer list.
linkedList::linkedList() : headEvent(nullptr), endPtr(nullptr), itemCount(0)
{}



// Destructor that also calls clear
linkedList::~linkedList()
{
    //clear();
   // headEvent = nullptr;
   // endPtr = nullptr;
}



bool linkedList::isEmpty()
{
    return( itemCount == 0);        
}



// Inserts data into the front of the linked list.
bool linkedList::insertFront(int toAdd, structure_type structureType)
{
    events *newData = new events(toAdd, structureType);
    bool sentinel = false;
    
    //If empty
    if(itemCount == 0)               //headEvent != nullptr)
    {
        newData->setNext(nullptr);
        headEvent = newData;
        endPtr = newData;
        sentinel = true;     
    }
    // otherwise append to the front of the list.
    else
    {
        newData->setNext(headEvent);
        headEvent = newData;        
    }
 
    newData = nullptr;
    itemCount++;
    return sentinel;
}



// Removes the back-most variable
bool linkedList::removeBack()
{   
    bool sentinel = false;
    
    // If the list is empty
    if(headEvent == nullptr && itemCount == 0)
    {
        sentinel = false;        
    }
    // If there is only one item in the list
    else if(headEvent->getNext() == nullptr && itemCount == 1)
    {
        delete headEvent;
        headEvent->setNext(nullptr);
        endPtr->setNext(nullptr);
        sentinel = true; 
        itemCount--;       
    }
    // otherwise
    else
    {
        events *curr = headEvent;
        events *prev = nullptr;
        
        // iterate through the list
        while(curr->getNext() != nullptr)
        {
            prev = curr;
            curr = curr->getNext();        
        }

        // reassign endPtr and delete the last node
        prev->setNext(nullptr);
        endPtr = prev;
        delete curr;
        curr = nullptr;
        prev = nullptr;
        itemCount--;

        sentinel = true;
    }

    return sentinel;
}



// CLEAR - used on the destructor method
void linkedList::clear()
{/*
    events *curr = nullptr;

    while(headEvent)
    {   
        curr = headEvent;
        headEvent = headEvent->getNext();
        //curr->setNext(nullptr);
        delete curr;
        curr = nullptr;
    }   
    
    itemCount = 0; */
}


// getter for sector Num
int linkedList::sendSector()
{
    return (endPtr->getData());
}


// getter for structureType
structure_type linkedList::sendStructure()
{
    return(endPtr->getStructure());        
}



