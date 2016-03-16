/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: jbur0473
 */

#include "Timer.h"
#include <iostream>
#include <iomanip> //Make output look nicer!
using namespace std;

Timer::Timer()
{
	executionTime = 0;
}

Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

//A method that displays all the information relevent to the timer.
void Timer::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " μs (microseconds) for the code " << endl;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC << " seconds" << endl;
}

//A method to start the timer.
void Timer::startTimer()
{
	executionTime = clock();
}

//A method to stop the timer and get the time running.
void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}

//A method to reset the timer should you want to time multiple different things in a single run.
void Timer::resetTimer()
{
	executionTime = 0;
}

//A method to turn the timers time in seconds into microseconds.
long Timer::getExecutionTimeInMicroseconds()
{
	return executionTime;
}

