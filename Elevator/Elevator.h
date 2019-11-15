#pragma once

#include <vector>
#include "Call.h"

class Elevator {

public:
	unsigned int capacity;
	unsigned int currentFloor = 0;
	std::vector<unsigned int> targetFloors;
	directions direction = up;

	Elevator(unsigned int capacity);

	void moveElevator(const unsigned int maxFloor);
	
	void dropOffTargets();

	void pickUpTargets(std::vector<Call>& callStack);

	bool changeDirection(int& favouredDirection);

};