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

template <class Type>
class HashTable
{
private:
    int capacity;
    double efficiencyPercentage;
    int size;
    HashNode<Type> ** internalStroage;
    int findPosition(HashNode<Type> currentNode);
    
};

#endif /* HashTable_hpp */
