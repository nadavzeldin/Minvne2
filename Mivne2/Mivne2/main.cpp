#include <iostream>
#include <ctype.h>
#include <string.h>
#include "BSTree.h"
#include "List.h"
using namespace std;
#define MAX 100

int NaivePrint(Node arr[], int n, int k);
void swap(Node* a, Node* b);
int BSTPrint(Node [], int n, int k);
int PrintBySort(Node arr[], int n, int k);
int partition(Node array[], int left, int right);

#define _CRT_SECURE_NO_WARNINGS
int main()
{
    //configs
    int n, k, v, comp;
    char firstName[MAX];
    char lastName[MAX];
    bool valid_name = false;

    //creating list
    List * lst = new List();

    //creating binary tree
    BSTree *tree = new BSTree();
    
    cout << "Please enter number of items: ";
    cin >> n;
    
    //creating array 
    Node *arr =  new Node[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter the id of person number #" << i + 1 << endl;
        cin >> k;
	    while(!valid_name)
	    {
            cout << "Please enter the first and last name of the person" << endl;
            cin >> firstName;
            cin >> lastName;	   
            if(firstName && lastName) { valid_name = true; }
            else { valid_name = false; }
	    }
        //inserting value to array , list and tree
        arr[i].setNode(k, firstName, lastName);
        lst->insert(k, firstName, lastName);
        tree->insert(k, firstName,lastName, tree->head);
	    valid_name = false;
    }
    for (int i=0; i<n; i++)
    {
        arr[i].printNode();
    }

    cout << "Enter ID number to check" << endl;
    cin >> v; // v is the comprasion value

    // NaivePrint
    comp = NaivePrint(arr, n, v);
    cout << "Naive Print: " << comp << " comprasions" << endl;
    
    //BSTPrint
    comp = BSTPrint(arr, n, v);
    cout << "BSTprint: " << comp << " comprasions" << endl;

    //PrintBySort

    comp = PrintBySort(arr, 0, v);
    cout << "PrintBySort: " << comp << " comprasions" << endl;


}

int NaivePrint(Node arr[], int n, int k){
    int compares = 0;
    List * ls = new List();
    for (int i = 0; i < n; i++)
    {
        if (arr[i].key_value < k)
        {
            ls->insertWithOrder(arr[i].key_value, arr[i].fstName, arr[i].lstName, compares);
        }
    }
    ls->printDS();

    return compares;
}


int BSTPrint(Node array[], int n, int k) 
{
    int compares = 0;
    BSTree *tree  = new BSTree();
    for(int i=0; i < n; i++)
    {
        tree->insert(array[i].key_value, array[i].fstName, array[i].lstName);
    }
    tree->printDS_key(k);
    return compares;
}


int PrintBySort(Node arr[], int left, int right)
{
    int pivot;

    if (left < right)
    {
        pivot = partition(arr, left,right);
        PrintBySort(arr, left, pivot - 1);
        PrintBySort(arr, pivot + 1, right);
    }
    return 1;
}

int partition(Node A[], int left, int right)
{
    bool pivotIsLeft = true;

    Node* p1 = A + left;
    Node* p2 = A + right;

    Node* tmpP;
    int index = 0;

    while (p1 != p2) // do while they are not the same one
    {
        //cout << "pivot is " << *p1 << ", second is " << *p2 << "\n";

        if (pivotIsLeft) // pivot(p1) is left
        {
            //cout << "pivot Is Left ";
            if (*p1 > * p2) {
                //cout << ", switch: ";
                swap(p1, p2);

                tmpP = p1;
                p1 = p2;
                p2 = tmpP;

                if (pivotIsLeft)
                    pivotIsLeft = false;
                else
                    pivotIsLeft = true;
            }

            if (pivotIsLeft)
                p2 -= 1;
            else
                p2 += 1;

            //printArr(A, 10);
        }
        else // pivot(p1) is right
        {
            //cout << "pivot Is Right ";
            if (p1->key_value < p2->key_value) {
                //cout << ", switch: ";
                swap(p1, p2);

                tmpP = p1;
                p1 = p2;
                p2 = tmpP;

                if (pivotIsLeft)
                    pivotIsLeft = false;
                else
                    pivotIsLeft = true;
            }

            if (pivotIsLeft)
                p2 -= 1;
            else
                p2 += 1;

            //printArr(A, 10);
        }


    }
    return p1 - A;
}

// Function to swap position of elements
void swap(Node* a, Node* b) 
{
    Node t = *a;
    *a = *b;
    *b = t;
}