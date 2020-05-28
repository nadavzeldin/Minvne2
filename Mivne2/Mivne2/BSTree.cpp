#include "BSTree.h"
BSTree::~BSTree()
{
    makeEmpty();
}

void BSTree::makeEmptyFN(Node* leaf)
{
    cout << leaf << endl;
    if (leaf == nullptr)
        return;
    else
    {
        makeEmptyFN(leaf->point[0]);
        makeEmptyFN(leaf->point[1]);
        delete leaf;
        return;
    }
}

void BSTree::printDS_key(int key)
{
    if(!head)
        return;
    else
        printTree(head, key);
}

void BSTree::printDS()
{
    if(!head)
        return;
    else
        printTree(head);
}

void BSTree::printTree(Node* node, int key)
{
    if(node->point[0])
        printTree(node->point[0], key);
    if(node->key_value < key)
        node->printNode();
    count++;

    if(node->point[1])
        printTree(node->point[1], key);
    return;
}

void BSTree::makeEmpty()
{
    makeEmptyFN(head);
}

bool BSTree::isEmpty()
{
    return head == nullptr;
}

void BSTree::insert(int k, string firstName, string lastName)
{
    insert(k,firstName,lastName, head);
}

void BSTree::insert(int k, string firstName, string lastName, Node *leaf)
{
    if (!head)
    {
        head = new Node(k, firstName, lastName);
    }
    else if(k < leaf->key_value)
    {
        count++;
        if(leaf->point[0])
            return insert(k, firstName, lastName, leaf->point[0]);
        else
        {
            leaf->point[0] = new Node(k,firstName, lastName);    
        }
    }
    else
    {
        count++;
        if(leaf->point[1])
        {
            return insert(k, firstName, lastName, leaf->point[1]);
        }
        else
        {
            leaf->point[1] = new Node(k, firstName, lastName);
        }
    }
}

Node* BSTree::search(int key, Node *leaf)
{
    if(!leaf)
    {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->point[0]);
        else
            return search(key, leaf->point[1]);
    }
    else return nullptr;
}

Node* BSTree::search(int key)
{
    return search(key, head);
}

