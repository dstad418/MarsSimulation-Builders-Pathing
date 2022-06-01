#include "builder.h"
#include "linkedList.h"
#include "structuretype.h"

// DELETE LATER
#include <iostream>
using namespace std;


// Member initializer list
builder::builder() : builderNum(0), tempSector(0)
{
}



bool builder::doCycle()
{
    bool sentinel = false;

    // IF IT'S NOT EMPTY, OTHERWISE RETURN FALSE.
    if(!runningList.isEmpty())
    {  
        // Print moving the builder, if applicable.
        if(tempSector != runningList.sendSector())
        {
            cout << "Builder #" << builderNum << ": Moving to sector " << runningList.sendSector() << endl;
            tempSector = runningList.sendSector();       
        }
        // Otherwise, the builder builds the structure and returns true
        cout << "Builder #" << builderNum << ": Building a " << str(runningList.sendStructure()) << " in sector " << tempSector << endl;

        runningList.removeBack();
        sentinel = true;
    }

    return sentinel; 
}



void builder::returnHome()
{   
    int sector = runningStack.peekSector();
    
    // While not empty and count is greater than 1--
    while(!runningStack.isEmpty() && (runningStack.countIs() > 0 ))
    {
        // moves to sector
        if(sector != runningStack.peekSector())
        {
            cout << "Builder #" << builderNum << ": Moving to sector " << runningStack.peekSector() << endl;
            sector = runningStack.peekSector(); 
        }
        // otherwise, connects the buildings together for the colonies
        cout << "Builder #" << builderNum << ": Connected to " << str(runningStack.peekStructureType()) << " in sector " << runningStack.peekSector() << endl;

        // pops off the stack.
        runningStack.pop();      
    }


    // When they finally arrive back at home base.
    cout << "Builder #" << builderNum << ": Arrived back at base." << endl;
}


// pushes request to the top of the stack
bool builder::addRequest(int sectorNum, structure_type type)
{
    cout << "Builder #" << builderNum << ": Received request to build a ";
    cout <<  str(type) << " in sector " << sectorNum << endl;

    // adds to the list and the stack
    runningList.insertFront(sectorNum, type);
    runningStack.push(sectorNum, type);

    return true;
}



void builder::setBuilderNum(const int &num)
{
    builderNum = num;
}



