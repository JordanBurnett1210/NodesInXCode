//
//  HashTable.cpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 5/9/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#include "HashTable.hpp"
#include "CTECList.h`"
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
int HashTable<Type> :: findPosition(const Type& value)
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
    int updatedCapacity getNextPrime();
    CTECList<HashNode<Type>> * updateTable = new CTECList<HashNode<Type>> [updatedCapacity];
    int oldTableCapacity = tableCapacity;
    tableCapacit = updatedCpacity;
    
    for(int index = 0; index < oldTableCapaty; index++)
    {
        if(tableStorage[index] != nullptr)
        {
            CTECList<HashNode<Type>> temp = tableStorage;
            for(int innerIndex = 0; innderIndex < temp.getSize(); innnerIndex++)
            {
                int updatedTblePosition = findPosition(temp.get(index));
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
void HashTable<Type> :: adToTable(HashNode<Type> currentNode)
{
    if(this->tableSize/this->tableCapacity >= this-efficiencyPercentage)
    {
        updateTableCapacity();
    }
    int positionToInsert = findTablePosition(currentNode);
    if(tableStroage[positionToInsert] == nullptr)
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
void HashTable<Type>  add(HashNode<Type> currentNode)
{
    if(!contains(currentNode))
    {
        if(this->size/this->capacity >= this-> efficiencyPercentage)
        {
            updateCapacity();
        }
        int positionToInsert = findPosition(currentNode);
        if(internalStroage[positionToInsert] != nullptr)
        {
            insertionIndex = handlCollision(currentNode);
            
            while(internalStorage)
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
        if(internalStroage[index] != nullptr)
        {
            int updatedPosition = findPosition(internalStroage[index]);
            updatedStorage[updatedPosition] = internalStroage[index];
        }
    }
    
    internalStroage = updatedStorage;
}

template <class Type>
bool HashTable<Type> :: contains(HashNode<Type> currentNode)
{
    bool isInTable = false;
    
    int index = findPosition(currentNode);
    while(internalStroage[index] != nullptr && !isInTable)
    {
        if(internalStroage[index].getValue() == currentNode.getValue())
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
    int randomEven = rand(cacity);
    reHashedPosition = (random + reHashedPosition * reHashedPosition) % capacity;
    
    return reHashedPosition;
}