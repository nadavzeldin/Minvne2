
#include "binaryTree.h"
#include "node.h"

binaryTree::binaryTree()
{
    head = new Node();
    root = head;
}


binaryTree::~binaryTree()
{
    makeEmpty();
}

void binaryTree::makeEmptyFN(Node* leaf)
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

void binaryTree::printDS()
{
    if(head == nullptr)
        return;
    else
    {
        printTree(head);
    }
    
}

void binaryTree::printTree(Node* node)
{
    if(node->point[0])
        printTree(node->point[0]);
    if(node->point[1])
        printTree(node->point[1]);
    node->printNode();
}

void binaryTree::makeEmpty()
{
    makeEmptyFN(head);
}

bool binaryTree::isEmpty()
{
    return head == nullptr;
}

//void binaryTree::insert(Node* data)
//{
//    insert(data, head);
//}

void binaryTree::insert(int k, char* firstName, char* lastName, Node * leaf)
{
    if (k < leaf->key_value)
    {
        if (leaf->point[0] != nullptr)
            insert(k, firstName, lastName, leaf->point[0]);
        else
        {
            leaf->point[0]->setNode(k, firstName, lastName);
            leaf->point[0]->point[0] = new Node();    //Sets the left child of the child node to null
            leaf->point[0]->point[1] = new Node();   //Sets the right child of the child node to null
        }
    }
    else if (k >= leaf->key_value)
    {
        if (leaf->point[1] != nullptr)
            insert(k, firstName, lastName, leaf->point[1]);
        else
        {
            leaf->point[1]->setNode(k, firstName, lastName);
            leaf->point[0] = new Node();    //Sets the left child of the child node to null
            leaf->point[1] = new Node();   //Sets the right child of the child node to null
        }
    }
}
//
//void binaryTree::insert(Node * insertLeaf, Node* leaf)
//{
//    if (insertLeaf->key_value < leaf->key_value)
//    {
//        if (leaf->point[0] != nullptr)
//            insert(insertLeaf, leaf->point[0]);
//        else
//        {
//            leaf->point[0] = insertLeaf;
//            insertLeaf->point[0] = nullptr;    //Sets the left child of the child node to null
//            insertLeaf->point[1] = nullptr;   //Sets the right child of the child node to null
//        }
//    }
//    else if (insertLeaf->key_value >= leaf->key_value)
//    {
//        if (leaf->point[1] != nullptr)
//            insert(insertLeaf, leaf->point[1]);
//        else
//        {
//            leaf->point[0] = insertLeaf;
//            insertLeaf->point[0] = nullptr;    //Sets the left child of the child node to null
//            insertLeaf->point[1] = nullptr;   //Sets the right child of the child node to null
//        }
//    }
//}


//
//void binaryTree::insert(int key, node* leaf)
//{
//    if (key < leaf->key_value)
//    {
//        if (leaf->left != nullptr)
//            insert(key, leaf->left);
//        else
//        {
//            leaf->left = new node;
//            leaf->left->key_value = key;
//            leaf->left->left = nullptr;    //Sets the left child of the child node to null
//            leaf->left->right = nullptr;   //Sets the right child of the child node to null
//        }
//    }
//    else if (key >= leaf->key_value)
//    {
//        if (leaf->right != nullptr)
//            insert(key, leaf->right);
//        else
//        {
//            leaf->right = new node;
//            leaf->right->key_value = key;
//            leaf->right->left = nullptr;  //Sets the left child of the child node to null
//            leaf->right->right = nullptr; //Sets the right child of the child node to null
//        }
//    }

Node * binaryTree::search(int key, Node *leaf)
{
    if (leaf != nullptr)
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

Node* binaryTree::search(int key)
{
    return search(key, head);
}

