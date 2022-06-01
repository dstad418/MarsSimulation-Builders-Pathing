
#ifndef _STACK
#define _STACK

#include "linkedList.h"
#include "events.h"

class stack
{
 private:
    events *eventsStackHead;
    int count;

 public:

    stack();
    ~stack();
    // DELETING THE COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR.
    stack(const stack& other) = delete;
    stack &operator=(const stack&) = delete;

    // getter for stack-count
    int countIs();
    bool isEmpty();

    // push & pop
    bool push(int sector, structure_type type);
    bool pop();

    // 'getters'
    int peekSector();
    structure_type peekStructureType();     

};

#endif
