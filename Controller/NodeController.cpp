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

void NodeController :: testLists()
{
	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is: " << numbers->getEnd() << endl;
}

void NodeController :: start()
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

