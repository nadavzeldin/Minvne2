#include <iostream>
#include <ctype.h>
#include <string.h>
#include "binaryTree.h"
#include "List.h"
using namespace std;
#define MAX 100

int NaivePrint(Node arr[], int n, int k);
void swap(Node* a, Node* b);
int PrintBySort(Node arr[], int n, int k);
int partition(Node array[], int low, int high);

#define _CRT_SECURE_NO_WARNINGS
int main()
{
    //configs
    int n,k, v, j =0;
    char firstName[MAX];
    char lastName[MAX];
    bool valid_name = false;

    //creating list
    List * lst = new List();

    //creating binary tree
    binaryTree * tree = new binaryTree();
    
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
	    cout << "first after " << firstName << endl;
	    cout << "last after " << lastName << endl;
	    if(firstName && lastName) { valid_name = true; }
	    else { valid_name = false; }
	    }
        //inserting value to array , list and tree
        arr[i].setNode(k, firstName, lastName);
        lst->insert(k, firstName, lastName);
        tree->insert(k, firstName,lastName, tree->head);
	    valid_name = false;
    }
    // NaivePrint
    NaivePrint(arr, n, 6);

    //PrintBySort
    PrintBySort(arr, n, k);

    cout << "Enter ID number to check" << endl;
    cin >> v; // v is the comprasion value
    for (int i=0; i<n; i++)
    {
        arr[i].printNode();
    }


    //need to print all items which id is less then k
        //BSTPrint
    return 0;
}

int NaivePrint(Node arr[], int n, int k){
    int compares = 0;
    List * ls = new List();
    for (int i = 0; i < n; i++)
    {
        if (arr[i].key_value < k)
        {
            ls->insertWithOrder(arr[i].key_value, arr[i].fstName, arr[i].lstName,compares);
        }
    }
    ls->printDS();
    cout << "\ncompares: ";
    cout<<compares;

    return compares;
}

int PrintBySort(Node arr[], int n, int k)
{
    int compares = 0;
    if (n < k) {
        // Select pivot position and put all the elements smaller than pivot on left and greater than pivot on right
        int pi = partition(arr, n, k);

        // Sort the elements on the left of pivot
        PrintBySort(arr, n, pi - 1);

        // Sort the elements on the right of pivot
        PrintBySort(arr, pi + 1, k);
    }
    return compares;
}

//Function to partition the array on the basis of pivot element
int partition(Node array[], int low, int high) {
    // Select the pivot element
    Node pivot = array[high];
    int i = (low - 1);

    // Put the elements smaller than pivot on the left and greater than pivot on the right of pivot
    for (int j = low; j < high; j++) {
        if (array[j].key_value <= pivot.key_value) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Function to swap position of elements
void swap(Node* a, Node* b) {
    Node t = *a;
    *a = *b;
    *b = t;
}