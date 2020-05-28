#ifndef __DS_H
#define __DS_H

#include "node.h"
/*"""
This is an abstract class that list
and tree inheritance the interface from
"""*/

class DS 
{
public: 
    Node* head = nullptr;
    int count = 0;
    int getCount() const;
    virtual ~DS() = default;
    virtual void makeEmpty() = 0;
    virtual bool isEmpty() = 0;
    virtual void printDS() = 0;
    virtual void insert(int k, string firstName, string lastName) = 0;
    
};
#endif // __DS_H