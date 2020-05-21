#include <iostream>
#include <ctype.h>
#include <string.h>
#include "binaryTree.h"
#include "List.h"
using namespace std;
#define MAX 100

int main()
{
    //configs
    int n,k, v, j =0;
    char firstName[MAX];
    char lastName[MAX];
    bool valid_name = false;

    //creating list
    List lst;

    //creating binary tree
    binaryTree tree;
    
    cout << "Please enter number of items: ";
    cin >> n;
    
    //creating array 
    Node *arr =  new Node[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter the id of person number " << i + 1 << endl;
        cin >> k;
	    while(!valid_name)
	    {
	    cout << "Please enter the first and last name of the person" << endl;
 	    cin >> firstName;
	    cin >> lastName;	   
	    cout << "first after " << firstName << endl;
	    cout << "last after " << lastName << endl;
	    if(firstName && lastName) { valid_name = true; }
	    else { valid_name = false; }
	    }
        //inserting value to array
        arr[i].setNode(k, firstName, lastName);
	    valid_name = false;
    }
    cout << "Enter ID number to check" << endl;
    cin >> v; // v is the comprasion value
    for (int i=0; i<n; i++)
    {
        arr[i].printNode();
    }
    //need to print all items which id is less then k
        // NaivePrint
        //BSTPrint
        //PrintBySort

    return 0;
}

