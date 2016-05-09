//
//  HashNode.hpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 5/9/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#ifndef HashNode_hpp
#define HashNode_hpp
#include "iostream"


template <class Type>
class HashNode
{
private:
    int key;
    Type value;
public:
    HashNode(int key, const Type& value);
    void setKey(int key);
    void setValue(const Type& value);
    int getKey();
    Type getValue();
};


#endif /* HashNode_hpp */
