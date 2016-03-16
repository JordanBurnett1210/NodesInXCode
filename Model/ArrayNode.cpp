/*
 * ArrayNode.cpp
 *
 *  Created on: Jan 29, 2016
 *      Author: jbur0473
 */

#include "ArrayNode.h"

template<class Type>
ArrayNode<Type>::ArrayNode() : Node<Type>()
{
	this->next = nullptr;
}

template<class Type>
ArrayNode<Type>::ArrayNode(const Type& value) : Node<Type>(value)
{
	this->value->setValue(value);
	this->next = nullptr;
}

template<class Type>
ArrayNode<Type>::ArrayNode(const Type& value, ArrayNode * next) : Node<Type>(value)
{
	this->value->setValue(value);
	this->next = next;
}

template<class Type>
ArrayNode<Type>::~ArrayNode()
{
	// TODO Auto-generated destructor stub
}

template<class Type>
ArrayNode<Type> * ArrayNode<Type>:: getNext()
{
	return this->next;
}

template<class Type>
void ArrayNode<Type> :: setNext(ArrayNode<Type> * next)
{
	this->next = next;
}
