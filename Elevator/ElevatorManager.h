#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Elevator.h"
#include "Call.h"

class ElevatorManager {

public:
	unsigned int floors;

	ElevatorManager(unsigned int floors);

	void addElevator(Elevator toAdd);

	void addElevator(unsigned int capacity = 10);

	void startElevatorSequence();

	//From here on can likely be private.
	void addToCallStack(std::vector<Call> &callStack);

private:
	std::vector<Elevator> elevators;

};