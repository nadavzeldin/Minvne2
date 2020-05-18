
#include "binaryTree.h"

binaryTree::binaryTree()
{
    root = nullptr;
}

binaryTree::~binaryTree()
{
    MakeEmpty();
}

void binaryTree::MakeEmpty(node * leaf)
{
    if (leaf == nullptr)
        return;
    else
    {
        MakeEmpty(leaf->left);
        MakeEmpty(leaf->right);
        delete leaf;
        return;
    }
}

void binaryTree::MakeEmpty()
{
    MakeEmpty(root);
}

void binaryTree::insert(node * insertLeaf, node* leaf)
{
    if (insertLeaf->key_value < leaf->key_value)
    {
        if (leaf->left != nullptr)
            insert(insertLeaf, leaf->left);
        else
        {
            leaf->left = insertLeaf;
            insertLeaf->left = nullptr;    //Sets the left child of the child node to null
            insertLeaf->right = nullptr;   //Sets the right child of the child node to null
        }
    }
    else if (insertLeaf->key_value >= leaf->key_value)
    {
        if (leaf->right != nullptr)
            insert(insertLeaf, leaf->right);
        else
        {
            leaf->left = insertLeaf;
            insertLeaf->left = nullptr;    //Sets the left child of the child node to null
            insertLeaf->right = nullptr;   //Sets the right child of the child node to null
        }
    }
}


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


node * binaryTree::search(int key, node *leaf)
{
    if (leaf != nullptr)
    {
        if (key == leaf->key_value)
            return leaf;
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return nullptr;
}

node* binaryTree::search(int key)
{
    return search(key, root);
}

