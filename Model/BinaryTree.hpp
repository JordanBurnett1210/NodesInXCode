//
//  BinaryTree.hpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 4/11/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include "TreeNode.cpp"

template <class Type>
class BinaryTree
{
private:
    TreeNode<Type>* root;
    int height;
    bool balanced;
    bool contains(Type value, BinaryTree<Type>* currentTree);
public:
    BinaryTree();
    ~BinaryTree();
    bool insert(const Type& value);
    bool contains(Type value);
    Type remove(const Type& value);
    int getHeit();
    bool isBalanced();
    TreeNode<Type>* getRoot();
};

#endif /* BinaryTree_hpp */
