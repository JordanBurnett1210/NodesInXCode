/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: jbur0473
 */

#include "NodeController.h"

NodeController::NodeController()
{
	notHipsterInts = new CTECArray<int>(3);
	numbers = new CTECList<int>();
}

NodeController::~NodeController()
{

}

void NodeController::testLists()
{
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is: " << numbers->getEnd() << endl;
}

void NodeController::checkSorts()
{
    /*
     Create an array and a list
     
     
     
     */
    CTECArray<int> numbersInArray(5000);
    CTECList<int> numbersInList;
    intcPlusPlusArray[5000];
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
	arrayTimer.startTimer();

	//Loops through all of "notHipsterInts, and sets the value at each position as 42 * the position #.
	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (42 * index));
	}

	//Loops through all of "notHipsterInts and prints all of it's information to the console.
	for (int index = 0; index < notHipsterInts->getSize(); index++)
	{
		cout << "notHipsterInts at index " << index << " contains " << notHipsterInts->get(index) << endl;
	}

	//Measures and displays the amount of time the previous methods took.
	arrayTimer.stopTimer();
	arrayTimer.displayTimerInformation();
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