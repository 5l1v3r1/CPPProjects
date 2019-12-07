#pragma once

#include <vector>
#include <limits>
#include "Call.h"

class Elevator {

public:
	unsigned int capacity;
	unsigned int currentFloor = 1;
	unsigned int targetFloor;
	std::vector<unsigned int> targetFloors;
	directions direction = up;

	Elevator(unsigned int capacity);

	void moveElevator(const unsigned int maxFloor);
	
	void dropOffTargets();

	void pickUpTargets(std::vector<Call>& callStack);

	bool changeDirection(int& favouredDirection, std::vector<Call>& callStack);

};