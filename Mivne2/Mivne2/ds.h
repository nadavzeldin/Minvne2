#ifndef __DS_H
#define __DS_H

#include "node.h"
/*"""
This is an abstract class that list
and tree inheritance the interface from
"""*/

class DS 
{
public: // need to implement at list and tree classes
    Node* head = nullptr;
    virtual ~DS() {}
    virtual void makeEmpty() = 0;
    virtual bool isEmpty() = 0;
    virtual void printDS() = 0;
    virtual void insert(Node* data) = 0;    

};
#endif // __DS_H