//
//  TreeNode.hpp
//  NodesInXCode
//
//  Created by Burnett, Jordan on 4/11/16.
//  Copyright © 2016 Burnett, Jordan. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include "Node.h"

template <class Type>
class TreeNode : public Node<Type>
{
private:
    TreeNode<Type> * leftChild;
    TreeNode<Type> * rightChild;
    TreeNode<Type> * parent;
public:
    TreeNode();
    TreeNode(const Type& value);
    TreeNode(const Type& value, TreeNode<Type> * parent);
    void setLeftChild(TreeNode<Type>* leftChild);
    void setRightChild(TreeNode<Type>* rightChild);
    void setParent(TreeNode<Type>* parent);
    TreeNode<Type> * getLeftChild();
    TreeNode<Type> * getRightChild();
    TreeNode<Type> * getParent();
};

#endif /* TreeNode_hpp */
