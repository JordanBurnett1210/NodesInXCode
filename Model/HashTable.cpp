//
//  HashTable.cpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 5/9/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#include "HashTable.hpp"

template<class Type>
HashTable<Type>::HashTable
{
    
}

template <class Type>
int HashTable<Type> :: findPosition(const Type& value)
{
    int position = 0;
    
    position = currentNode.getKey() % capacity;
    
    return position;
}