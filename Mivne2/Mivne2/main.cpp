#include <iostream>
#include <ctype.h>
#include <string>
#include "BSTree.h"
#include "List.h"
using namespace std;
#define MAX 100

int NaivePrint(Node arr[], int n, int k);
void swap(Node* a, Node* b);
int BSTPrint(Node [], int n, int k);
int PrintBySort(Node arr[], int n, int k);
int partition(Node array[], int left, int right, int &comp);

#define _CRT_SECURE_NO_WARNINGS
int main()
{
    //configs
    int n, k, v, comp;
    string firstName;
    string lastName;
    bool valid_name = false;

    //creating list
    List * lst = new List();

    //creating binary tree
    BSTree *tree = new BSTree();
    
    cout << "Please enter number of items: " << endl;
    cin >> n;
    
    //creating array 
    Node *arr =  new Node[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter the id of person number #" << i + 1 << endl;
        cin >> k;
        cout << "Please enter the first and last name of the person" << endl;
        cin >> firstName;
        cin >> lastName;	   
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

    comp = PrintBySort(arr, 0, n);
    cout << "PrintBySort: " << comp << " comprasions" << endl;


}

int NaivePrint(Node arr[], int n, int k){
    List * ls = new List();
    for (int i = 0; i < n; i++)
    {
        if (arr[i].key_value < k)
        {
            ls->insertWithOrder(arr[i].key_value, arr[i].fstName, arr[i].lstName);
        }
    }
    ls->printDS();

    return ls->getCount();
}

int BSTPrint(Node array[], int n, int k) 
{
    BSTree *tree  = new BSTree();
    for(int i=0; i < n; i++)
    {
        tree->insert(array[i].key_value, array[i].fstName, array[i].lstName);
    }
    tree->printDS_key(k);
    return tree->getCount();
}


int PrintBySort(Node arr[], int left, int right)
{
    int pivot;
    int compares = 0;
    if (left < right)
    {
        pivot = partition(arr, left, right, compares);
        compares += PrintBySort(arr, left, pivot - 1);
        compares += PrintBySort(arr, pivot + 1, right);
    }
    return compares;
}

int partition(Node A[], int left, int right, int &comp)
{
    Node pivot = A[right];
    int locCounter = 0;
    int i = left - 1;
    for (int j = left; j <= right-1; j++)
    {
        locCounter++;
        if(A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[right]);
    comp += locCounter;
    return (i+1);
}

// Function to swap position of elements
void swap(Node* a, Node* b) 
{
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}