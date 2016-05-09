//
//  Graph.hpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 4/25/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp
#include <set>


template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool edges [MAXIMUM][MAXIMUM];
    Type labels [MAXIMUM];
    int manyVertices;
    void depthFirstTraversal(Graph<Type> currentGraph, int vertex, bool*markedVertices);
public:
    Graph();
    ~Graph();
    
    void addVertex(const Type& label);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator[](int vertex);
    int size();
    bool isEdge(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    Type operator[](int vertex)const;
    void depthFirstTraversal(Graph<Type> currentGraph, int vertex);
    void breadthFirstTraversal(Graph<Type> currentGraph, int vertex);
};


#endif /* Graph_hpp */
