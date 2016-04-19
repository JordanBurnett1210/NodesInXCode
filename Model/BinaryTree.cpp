//
//  BinaryTree.cpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 4/11/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#include "BinaryTree.hpp"

using namespace std;

template <class Type>
BinaryTree<Type> :: BinaryTree()
{
    root = nullptr;
    height = 0;
    balanced = true;
    size = 0;
}

template <class Type>
bool BinaryTree<Type> :: insert(const Type& value)
{
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(value < root->getValue())
        {
            insert(value, root->getLeftChild());
        }
        else
        {
            insert(value, root->getRightChild());
        }
        return true;
    }
}

template <class Type>
void BinaryTree<Type> :: insrt(const Type& value, BinaryTree<Type> * currentTree)
{
    
}

template <class Type>
void BinaryTree<Type> :: inorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        inorderTraversal(currentNode->getLeftChild());
        cout << currentNode->getValue() < " " ;
        inorderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void BinaryTree<Type> :: preorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getValue() < " " ;
        preorderTraversal(currentNode->getLeftChild());
        preorderTraversal(currentNode->getRightChild());
    }
}

template <class Type>
void BinaryTree<Type> :: postorderTraversal(TreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postorderTraversal(currentNode->getLeftChild());
        postorderTraversal(currentNode->getRightChild());
        cout << currentNode->getValue() < " " ;
    }
}

template <class Type>
int BinaryTree<Type> :: getSize()
{
    int currentSize = 0;
    
    calculateSize(root);
}

template <class Type>
void BinaryTree<Type> :: calculateSize(TreeNode<Type> * currentNode)
{
    
    if(currentNode!= nullptr)
    {
        calculateSize(currentNode->getLeftCild());
        calculateSize(currentNode->getRightChild());
        size++;
    }
}

template <class Type>
bool BinaryTree<Type> :: contains(Type value)
{
    if(currentTree == nullptr)
    {
        return false;
    }
    if(currentTree>getRoot()->getValue() == value)
    {
        return true;
    }
    else if(value < currentTree->getRoot()->getValue())
    {
        return contains(value, root->getLeftChild());
    }
    else
    {
        return contains(value, root->getRightChild());
    }
    return false
}

template <class Type>
bool BinaryTree<Type> :: contains(Type value, BinaryTree<Type> * currentTree)
{
    if(currentTree == nullptr)
    {
        return false;
    }
    if(currentTree>getRoot()->getValue() == value)
    {
        return true;
    }
    else if(value < currentTree->getRoot()->getValue())
    {
        return contains(value, root->getLeftChild());
    }
    else
    {
        return contains(value, currentTree->etToot()->getRightChild());
    }
    return false;
}