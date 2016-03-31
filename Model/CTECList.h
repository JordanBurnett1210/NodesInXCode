/*
 * CTECList.h
 *
 *  Created on: Feb 22, 2016
 *      Author: jbur0473
 */

#ifndef MODEL_CTECLIST_H_
#define MODEL_CTECLIST_H_

#include "ArrayNode.h"

template <class Type>
class CTECList
{
private:
	int size;
	ArrayNode<Type> * head;
	ArrayNode<Type> * end;
	void calculateSize();
    void swap(int indexOne, int indexTwo);
public:
	CTECList();
	virtual ~CTECList();
	void addToFront(const Type& value);
	void addToEnd(const Type& value);
	void addAtIndex(int position, Type value);
	Type getFront();
	Type getEnd();
	Type getFromIndex(int position);
	Type removeFromFront();
	Type removeFromEnd();
	Type removeFromIndex(int index);
	int getSize();
	void setSize();
    int indexOf(Type searchValue);
    void selectionSort();
};

#endif /* MODEL_CTECLIST_H_ */
