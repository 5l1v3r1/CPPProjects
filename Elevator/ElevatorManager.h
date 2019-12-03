#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
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

private:
	std::vector<Elevator> elevators;

	void addToCallStack(std::vector<Call> &callStack);

	void drawSequence(std::vector<Elevator> elevators, std::vector<Call> callStack);

};