/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jbur0473
 */

#include "NodeController.h"
#include "../Model/Graph.cpp"

NodeController::NodeController()
{
	
}

NodeController::~NodeController()
{

}

void NodeController::testLists()
{
	
}

void NodeController::checkSorts()
{
    /*
     Create an array and a list
     
     
     
     */
    CTECArray<int> numbersInArray(5000);
    CTECList<int> numbersInList;
    int cPlusPlusArray[5000];
    for(int spot = 0; spot < 5000; spot++)
    {
        int randomValue = rand();
        numbersInArray.set(spot, randomValue);
        numbersInList.addToEnd(randomValue);
        cPlusPlusArray[spot] = randomValue;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    numbersInList.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    sortTimer.startTimer();
}

void NodeController::start()
{
    tryTree();
}

void NodeController::tryTree()
{
    BinaryTree<int> testTree;
    testTree.insert(7);
    testTree.insert(10);
    testTree.insert(-5);
    testTree.insert(9);
}

void NodeController::testList()
{
    
}

void NodeController::searchTest()
{
    
}

void NodeController::sortData()
{
    
}

void NodeController::doMergeSort()
{
    mergeData =  new int[5000];
    
    for(int spot = 0; spot < 5000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    mergeSort(mergeData, 5000);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
}

void NodeController::mergeSort(int data[], int size)
{
    int sizeOne;
    int sizeTwo;
    
    if(size > 1)
    {
        sizeOne = size/2;
        sizeTwo = size - sizeOne;
        
        mergeSort(data, sizeOne);
        mergeSort((data + sizeOne), sizeTwo);
        
        merge(data, sizeOne, sizeTwo);
    }
}

void NodeController::merge(int data[], int sizeOne, int sizeTwo)
{
    int * temp;     //link for a temp array
    int copied = 0;
    int copied1 = 0;
    int copied2 = 0;
    int index;
    
    temp = new int[sizeOne + sizeTwo];
    
    while((copied1 < sizeOne) && (copied2 < sizeTwo))
    {
        if(data[copied1] < (data + sizeOne)[copied2]) // smaller goes in small half
        {
            temp[copied++] = data[copied1++];
        }
        else    // larger goes in lare half
        {
            temp[copied++] = (data + sizeOne)[copied2++];
        }
    }
    
    while(copied1 < sizeOne)
    {
        temp[copied++] = data[copied1++];
    }
    
    while(copied2 < sizeTwo)
    {
        temp[copied++] = (data + sizeOne)[copied2++];
    }
    
    for(index = 0; index < sizeOne + sizeTwo; index++)
    {
        data[index] = temp[index];
    }
    
    delete [] temp;
    

}

void NodeController::quicksort(int first, int last)
{
    int pivotIndex;
    
    if(first < last)
    {
        pivotIndex = partition(first, last);
        quicksort(first, pivotIndex-1);
        quicksort((pivotIndex + 1), last);
        
    }
}

int NodeController::partition(int first, int last)
{
    int pivot;
    
    int index, smallIndex;
    swap(first, (first + last)/2);
    
    pivot = mergeData[first];
    smallIndex = first;
    
    for(index= first + 1; index <= last; index++)
    {
        if(mergeData[index] < pivot)
        {
            smallIndex++;
            swap(smallIndex, index);
        }
    }
    swap(first, smallIndex);
    
    return smallIndex;
}

void NodeController::swap(int first, int last)
{
    int temp = mergeData[first];
    mergeData[first] = mergeData[last];
    mergeData[last] = temp;
    
}

void NodeController::doQuick()
{
    mergeData = new int[500000];
    
    for(int spot = 0; spot < 500000; spot++)
    {
        int myRandom = rand();
        mergeData[spot] = myRandom;
    }
    Timer mergeTimer;
    mergeTimer.startTimer();
    quicksort(0, 499999);
    mergeTimer.stopTimer();
    mergeTimer.displayTimerInformation();
    
    delete [] mergeData;
}

void NodeController::tryGraphs()
{
    Graph<int> testerGraph;
    testerGraph.addVertex(7);
    testerGraph.addVertex(18);
    testerGraph.addVertex(12);
    testerGraph.addVertex(20);
    testerGraph.addVertex(5);
    testerGraph.addVertex(10);
    testerGraph.addVertex(23);
    testerGraph.addVertex(21);
    testerGraph.addVertex(16);
    
    testerGraph.addEdge(7,18);
    testerGraph.addEdge(18,12);
    testerGraph.addEdge(12,20);
    testerGraph.addEdge(20,5);
    testerGraph.addEdge(5,10);
    testerGraph.addEdge(10,23);
    testerGraph.addEdge(23,21);
    testerGraph.addEdge(21,16);
    
    testerGraph.depthFirstTraversal(testerGraph, 7);
    testerGraph.breadthFirstTraversal(testerGraph, 7);
    
}