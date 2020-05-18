#include <iostream>
#include "binaryTree.h"
#include "List.h"
using namespace std;


int main()
{
    //configs
    int n,k;
    char firstName[100];
    char lastName[100];

    //creating list
    List lst;
    lst.MakeEmpty();

    //creating binary tree
    binaryTree tree;
    tree.MakeEmpty();
    
    cout << "Please enter number of items: ";
    cin >> n;
    
    //creating array 
    listNode * arr =  new listNode[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter id and first name and last name";
        cin >> k;
        cin >> firstName;
        //need to check whitepace between first and last name
        cin >> lastName;
    }

    //need to print all items which id is less then k
        // NaivePrint
        //BSTPrint
        //PrintBySort

    return 0;
}