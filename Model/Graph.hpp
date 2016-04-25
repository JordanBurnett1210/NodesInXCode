//
//  Graph.hpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 4/25/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
public:
    Graph();
    ~Graph();
    
    void addVertex(const Type& label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator[](int vertex);
    
};


#endif /* Graph_hpp */
