/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: jbur0473
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_

#include <string>
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/Timer.h"
#include "../Model/CTECList.cpp"
#include "../Model/BinaryTree.cpp"

//////////////////////////////////////////////////////////
class NodeController                                    //
{                                                       //
private:                                                //
	                   //
	Timer arrayTimer;                                   //
	                          //
    void sortData();                                    //
    void testList();                                    //
    int * mergeData;                                    //
    void searchTest();                                  //
    void setupRandomArray();                            //
    void doMergeSort();                                 //
    void doBogo();
    void bogoSort();
    
    void swap(int first, int second);
    void quicksort(int first, int last);
    int partition(int first, int last);
    void doQuick();
    void tryTree();
    void mergeSort(int dataArray [], int size);         //
    void merge(int data [], int sizeOne, int sizeTwo);  //
public:                                                 //
    void checkSorts();                                  //
	NodeController();                                   //
	virtual ~NodeController();                          //
	void testLists();                                   //
	void start();                                       //
};                                                      //
                                                        //
#endif /* CONTROLLER_NODECONTROLLER_H_ */               //
//////////////////////////////////////////////////////////
