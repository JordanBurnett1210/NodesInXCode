/*
 * CTECList.cpp
 *
 *  Created on: Feb 22, 2016
 *      Author: jbur0473
 */

#include "CTECList.h"
#include <assert.h>

using namespace std;

template <class Type>
CTECList<Type>::CTECList()
{
	this->size = 0;
	this->head = nullptr;
	this->end = nullptr;

}

template <class Type>
CTECList<Type>::~CTECList()
{
	/*
	 * 1: Start at head
	 * 2: Iterate over nodes
	 * 3: Update position, then delete
	 * 4: Delete final
	 * 5: reset size, head, and end to 0/nullptr
	 */
	ArrayNode<Type> * current = head;

	for(int deleteCount = 0; deleteCount < size; deleteCount++)
	{
		ArrayNode<Type> * temp = current;

		current = current->getNext();
		head = current;
		delete temp;
	}

	this->size =0;
	this->head = nullptr;
	this->end = nullptr;
}

template <class Type>
Type CTECList<Type> :: removeFromFront()
{
	Type returnValue; //In case we need to use the value we are removing.

	assert(size > 0);
	//Create a pointer to what is after head.
	ArrayNode<Type> * newHead = new ArrayNode<Type>();
	newHead = head->getNext();

	//Get what was in the head node!
	returnValue = head->getValue();
	//Delete what head is pointing to.
	delete this->head;
	//Set head to the new head.
	this->head = newHead;

	this->calculateSize();
	return returnValue;
}

template <class Type>
Type CTECList<Type> :: removeFromIndex(int index)
{
	Type returnValue;

	assert(size > 0);
	assert(index >= 0);
	assert(index < size);

	Type thingToRemove;

	ArrayNode<Type> * previous, deleteMe, newNext;

	if(index == 0)
	{
		thingToRemove = removeFromFront();
	}
	else if(index == size-1)
	{
		thingToRemove = removeFromEnd();
	}
	else
	{
		for(int spot = 0; spot < index+1; spot++)
		{
			newNext = newNext->getNext();
		}

		thingToRemove = deleteMe->getValue();
		previous->setNext(newNext);
		delete deleteMe;

		this->calculateSize();
		return thingToRemove;
	}

}

template <class Type>
Type CTECList<Type> :: removeFromEnd()
{
	//Loop over size
	//or
	//Loop until getNext()->getNext() == nullptr
	//grab the value from the last node
	//set the next to last node to point to nullptr
	//set the next to last node as end
	//delete the old last node
	//Before return the variable call calculateSize()
	//return value

	Type thingToRemove;

	assert(this->size > 0);

	if(size == 1)
	{
		thingToRemove = removeFromFront();
		end = nullptr;
		calculateSize();
		return thingToRemove;
	}
	else
	{
		ArrayNode<Type> * current = head;
		for(int spot = 0; spot < size-1; spot++)
		{
			current = current->getNext();
		}

		thingToRemove = current ->getNext()->getValue();
		end = current;
		delete current->getNext();
		return thingToRemove;
	}
}


//Calculates the size of the list by iterating over all the nodes in the list.
template <class Type>
void CTECList<Type> :: calculateSize()
{
	assert(size >= 0);

	ArrayNode<Type> * counterPointer = head;
	int count = 0;

	if(counterPointer == nullptr)
	{
		this->size = 0;
		return;
	}
	else
	{
		count++;
		while(counterPointer->getNext() != nullptr)
		{
			counterPointer = counterPointer->getNext();
			count++;

		}
		this->size == count;
		return;
	}

}

template <class Type>
void CTECList<Type> :: addToFront(const Type& value)
{
	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value, head);
	head = newStuff;

	calculateSize();
}

template <class Type>
void CTECList<Type> :: addToEnd(const Type& value)
{
	ArrayNode<Type> * newStuff = new ArrayNode<Type>(value);
	end->setNext(newStuff);
	end = newStuff;

	calculateSize();
}

template <class Type>
void CTECList<Type> :: addAtIndex(int Index, Type value)
{
	ArrayNode<Type> * previous = head;
	ArrayNode<Type> * newValue = new ArrayNode<Type>(value);
	for(int i = 0; i < Index; i++)
	{
		previous = previous->getNext();
	}
	ArrayNode<Type> * newNext = previous->getNext();
	previous->setNext(newValue);
	newValue->setNext(newNext);
}

template <class Type>
Type CTECList<Type> :: getFront()
{

}

