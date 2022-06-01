#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "structuretype.h"
#include "events.h"

class linkedList
{
  private:
    events *headEvent;
    events *endPtr;
    int itemCount;

  public:
    linkedList();
    ~linkedList();
    // DELETING THE ASSIGNMENT OPERATOR AND COPY CONSTRUCTOR
    linkedList(const linkedList& other) = delete;
    linkedList &operator=(const linkedList&) = delete;


    bool isEmpty();
    bool insertFront(int toAdd, structure_type structureType);
    bool removeBack();
    int sendSector();
    structure_type sendStructure();

    void clear();        
        
};

#endif
