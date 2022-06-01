#include "stack.h"
#include "structuretype.h"

// NO OUTPUT ALLOWED IN THIS CLASS!!!


stack::stack() : eventsStackHead(nullptr), count(0)
{       
}


stack::~stack()
{
    // NOTHING TO BE DONE, ALL OF THE STACKS ARE POPPED
    eventsStackHead = nullptr;

}

// getters
int stack::countIs()
{
    return count;        
}

// getter
bool stack::isEmpty()
{
    return (count < 0);
}


// push
bool stack::push(int sector, structure_type type)
{
    bool sentinel = false;
    events *newPtr = new events(sector, type);
    newPtr->setNext(nullptr);

    // If empty
    if(eventsStackHead == nullptr)
    {
        eventsStackHead = newPtr;
        sentinel = true;        
    }
    // otherwise...
    else
    {
        newPtr->setNext(eventsStackHead);
        eventsStackHead = newPtr;
        sentinel = true;
    }

    count++;
    newPtr = nullptr;

    return sentinel;
}

// pop
bool stack::pop()
{
    bool sentinel = false;

    // only do the following if not empty;
    if(!isEmpty())
    {
        events *delPtr = eventsStackHead;
        eventsStackHead = eventsStackHead->getNext();
        
        delete delPtr;
        delPtr = nullptr;
        sentinel = true;       
    
        count--;            
    }
    
    return sentinel;
}

// getters!
int stack::peekSector()
{
    return (eventsStackHead->getData());                
}

structure_type stack::peekStructureType()
{
    return (eventsStackHead->getStructure());        
}
