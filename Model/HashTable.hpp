//
//  HashTable.hpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 5/9/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include "HashNode.cpp"
#include "CTECList.h"

template <class Type>
class HashTable
{
private:
    
    int capacity;
    double efficiencyPercentage;
    int size;
    HashNode<Type> ** internalStorage;
    CTECList<HashNode <Type>*> tableStorage;
    int findTablePosition(HashNode<Type> currentNode);
    int chainedCapacity;
    int chainedSize;
    void updateChainedCapacity();
    int handleCollision(HashNode<Type> currentNode);
    void updateCapacity();
    int getNextPrime();
    bool isPrime(int canidateNumber);
public:
    int findPosition(HashNode<Type> currentNode);
    void updateTableCapacity();
    HashTable();
    ~HashTable();
    void add(HashNode<Type> currentNode);
    void updateSize();
    void addToTable(HashNode<Type> currentNode);
    bool contains(HashNode<Type> currentNode);
};

#endif /* HashTable_hpp */
