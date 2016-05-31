//
//  HashTable.cpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 5/9/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#include "HashTable.hpp"
#include "CTECList.h"
#include <cmath>

template<class Type>
HashTable<Type>::HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->internalStroage = new HashNode<Type>[capacity];
    this->tableStorage = new CTECList<HashNode <Type>>[capacity];
}

template <class Type>
int HashTable<Type> :: findPosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template <class Type>
int HashTable<Type> :: findTablePosition(HashNode<Type> currentNode)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}

template <class Type>
int HashTable<Type> :: getNextPrime()
{
    int nextPrime = (capacity*2)+1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    
    return nextPrime;
}

template <class Type>
void HashTable<Type> :: updateTableCapacity()
{
    int tableCapacity;
    int updatedCapacity = getNextPrime();
    CTECList<HashNode<Type>> * updateTable = new CTECList<HashNode<Type>> [updatedCapacity];
    int oldTableCapacity = tableCapacity;
    tableCapacity = updatedCapacity;
    
    for(int index = 0; index < oldTableCapacity; index++)
    {
        if(tableStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = tableStorage;
            for(int innerIndex = 0; innerIndex < temp.getSize(); innerIndex++)
            {
                int updatedTablePosition = findPosition(temp.get(index));
                if(updateTable[updatedTablePosition] == nullptr)
                {
                    CTECList<HashNode<Type>> updatedList;
                    updatedList.addEnd(temp.get(index));
                }
                else
                {
                    updateTable[updatedTablePosition].ddEnd(temp.get(index));
                }
            }
        }
    }
    tableStorage = updateTable;
}

template <class Type>
void HashTable<Type> :: addToTable(HashNode<Type> currentNode)
{
    if(this->tableSize/this->tableCapacity >= this-efficiencyPercentage)
    {
        updateTableCapacity();
    }
    int positionToInsert = findTablePosition(currentNode);
    if(tableStorage[positionToInsert] == nullptr)
    {
        CTECList<HashNode<Type>> hashList;
        tableStorage[positionToInsert] = hashList;
        hashList.addEnd(currentNode);
    }
    else
    {
        tableStorage[positionToInsert].addEnd(currentNode);
    }
}

template <class Type>
void HashTable<Type> :: add(HashNode<Type> currentNode)
{
    int insertionIndex;
    if(!contains(currentNode))
    {
        if(this->size/this->capacity >= this-> efficiencyPercentage)
        {
            updateCapacity();
        }
        int positionToInsert = findPosition(currentNode);
        if(internalStorage[positionToInsert] != nullptr)
        {
            insertionIndex = handleCollision(currentNode);
            
            while(internalStorage)
            {
                
            }
        }
    }
        
}

template <class Type>
void HashTable<Type> :: updateSize()
{
    int updatedCapacity = getNextPrime();
    HashNode<Type> * updatedStorage = new HashNode<Type>[updatedCapacity];
    
    int oldCapacity = capacity;
    capacity = updatedCapacity;
    
    for(int index = 0; index < oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStorage[index]);
            updatedStorage[updatedPosition] = internalStorage[index];
        }
    }
    
    internalStorage = updatedStorage;
}

template <class Type>
bool HashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    
    int index = findPosition(currentNode);
    while(internalStorage[index] != nullptr && !isInTable)
    {
        if(internalStorage[index].getValue() == currentNode.getValue())
        {
            isInTable = true;
        }
        else
        {
            index = (index + 1) % capacity;
        }
    }
    return isInTable;
}

template <class Type>
int HashTable<Type> :: handleCollision(HashNode<Type> currentNode)
{
    int reHashedPosition = findPosition(currentNode);
    int randomEven = rand(capacity);
    reHashedPosition = (randomEven + reHashedPosition * reHashedPosition) % capacity;
    
    return reHashedPosition;
}