#ifndef _BUILDER
#define _BUILDER

#include "stack.h"
#include "linkedList.h"
#include "structuretype.h"



class builder
{
    private:
        stack runningStack;
        linkedList runningList;
    
        int builderNum;
        int tempSector;
   
    
    public:      
        builder();
        
        /* Process oldestrequest in LL and remove
         *      if empty, do nothing
         *      if something is build
         *          return true
         *          otherwise return false*/
        bool doCycle();
        
        /*Backtrack and print in reverse order- print and pop?*/
        void returnHome();

        /* take in a new entry or enum?*/
        bool addRequest(int sectorNum, structure_type building);

        // sets the builders ID
        void setBuilderNum(const int &num);
        
};



#endif
