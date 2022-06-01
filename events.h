#ifndef _EVENTS
#define _EVENTS

#include "structuretype.h"

class events
{
 private:

 // Loose data in lieu of a 'node'
    int sector;
    structure_type structure;
    events *next;

 public:       

// Constructor, destructor, deleting operators, etc.
    events();
    events(int setData, structure_type sType);
    ~events();
    // DELETING THE COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR.
    events(const events& other) = delete;
    events &operator=(const events&) = delete;
 
    // getters
    events* getNext();
    structure_type getStructure();
    int getData();
    
    // setters;
    bool setData(int toBeSet);
    bool setStructure(structure_type type); 
    bool setNext(events *location);

};
#endif
