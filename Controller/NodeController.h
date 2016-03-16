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

//////////////////////////////////////////////
class NodeController						//
{											//
private:									//
	CTECArray<int> * notHipsterInts;		//
	Timer arrayTimer;						//
	CTECList<int> * numbers;				//
public:										//
	NodeController();						//
	virtual ~NodeController();				//
	void testLists();

	void start();							//
};											//
											//
#endif /* CONTROLLER_NODECONTROLLER_H_ */	//
//////////////////////////////////////////////
