#include "events.h"
#include "structuretype.h"

// M.I.L.
events::events(): sector(0), next(nullptr)
{}

// constructor
events::events(int setData, structure_type sType)
{
    sector = setData;
    structure = sType;
    next = nullptr;        
}

// destructor
events::~events()
{
    next = nullptr;        
}

// getters
events* events::getNext()
{
    return next;        
}

structure_type events::getStructure()
{
    return structure;        
}

int events::getData()
{
    return sector;        
}


// setters (MOST OF THERE ENDED UP BEING REDUNDANT)
bool events::setData(int toBeSet)
{
    sector = toBeSet;
    return true;
}

bool events::setStructure(structure_type type)
{
    structure = type;
    return true;       
}

bool events::setNext(events *location)
{
    next = location;
    return true;        
}
