
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

void BSTree::insert(int k, char* firstName, char* lastName)
{
    insert(k,firstName,lastName, head);
}

void BSTree::insert(int k, char* firstName, char* lastName, Node * leaf)
{
    if (!head)
    {
        head = new Node(k, firstName, lastName);
        return;
    }
    else if (k < leaf->key_value)
    {
        if (leaf->point[0] != nullptr)
            insert(k, firstName, lastName, leaf->point[0]);
        else
        {
            leaf->point[0] = new Node();    //Sets the left child of the child node to null
            leaf->point[0]->setNode(k, firstName, lastName);
        }
    }
    else if (k >= leaf->key_value)
    {
        if (leaf->point[1] != nullptr)
            insert(k, firstName, lastName, leaf->point[1]);
        else
        {
            leaf->point[1] = new Node();   //Sets the right child of the child node to null
            leaf->point[1]->setNode(k, firstName, lastName);
        }
    }
}
//
//void BSTree::insert(Node * insertLeaf, Node* leaf)
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
//void BSTree::insert(int key, node* leaf)
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

Node * BSTree::search(int key, Node *leaf)
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

Node* BSTree::search(int key)
{
    return search(key, head);
}

