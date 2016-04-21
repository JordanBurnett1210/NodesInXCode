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
BinaryTree<Type> :: ~BinaryTree()
{
    while(root != nullptr)
    {
        remove(root);
    }
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
void BinaryTree<Type> :: insert(const Type& value, BinaryTree<Type> * currentTree)
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

template <class Type>
void BinaryTree<Type> :: remove(const Type& value)
{
    TreeNode<Type> * current = root;
    TreeNode<Type> * trailing = current;
    if(!contains(value))
    {
        return;
    }
    else
    {
        while(current != nullptr && current->getValue() != value)
        {
            trailing = current;
            if(current->getValue() > value)
            {
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }
        
        if(current == root)
        {
            remove(root);
        }
        else if(trailing->getValue() > value)
        {
            remove(trailing->getLeftChild);
        }
        else
        {
            remove(trailing->getRightChild);
        }
    }
}

template <class Type>
void BinaryTree<Type> :: remove(TreeNode<Type> * nodeToRemove)
{
    TreeNode<Type> * current;
    TreeNode<Type> * trailing;
    TreeNode<Type> * temp;
    
    if(nodeToRemove == nullptr)
    {
        cerr<< "It wasnt even there..." << endl;
    }
    else if(nodeToRemove->getRightChild() == nullptr && nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = nullptr;
        delete temp;
    }
    else if(nodeToRemove->getRightChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getLeftChild();
        delete temp;
    }
    else if(nodeToRemove->getLeftChild() == nullptr)
    {
        temp = nodeToRemove;
        nodeToRemove = temp->getRightChild();
        delete temp;
    }
    else
    {
        current = nodeToRemove->getLeftChild();
        trailing = nullptr;
        while(current->getRightChild != nullptr)
        {
            trailing = current;
            current = current->getRightChild();
        }
        
        nodeToRemove->setValue(current->getValue());
        
        if(trailing == nullptr)
        {
            nodeToRemove->setLeftChild(current->getLeftChild());
        }
        else
        {
            trailing->setRightChild(current->getLeftChild());
        }
        
        delete current;
    }
}

template <class Type>
bool BinaryTree<Type> :: insert(const Type& value)
{
    TreeNode<Type> * insertedNode(value);
    TreeNode<Type> * current;
    TreeNode<Type> * trailingCurrent;
    assert(insertedNode != nullptr);
    
    if(contains(value))
    {
        return false;
    }
    else
    {
        if(root == nullptr)
        {
            root = insertedNode;
        }
        else
        {
            current = root;
            
            while(current != nullptr)
            {
                trailingCurrent = current;
                
                if(current->getValue() > value)
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
            if(trailingCurrent->getValue() > value)
            {
                trailingCurrent->setLeftChild(insertedNode);
            }
            else
            {
                trailingCurrent->setRightChild(insertedNode);
            }
            insertedNode->setParent(trailingCurrent);

        }
        return true;
    }
}