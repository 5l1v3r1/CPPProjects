#pragma once

#include "Elevator.h"

struct Call {

	unsigned int FromFloor;
	unsigned int TargetFloor;

};

class ElevatorManager {

public:
	unsigned int floors;

	ElevatorManager(unsigned int floors);

	void addElevator(Elevator toAdd);

	void addElevator(unsigned int capacity);

	void startElevatorSequence();

	//From here on can likely be private.
	void addToCallStack(std::vector<Call> &callStack);

private:
	std::vector<Elevator> elevators;

	directions findCallDir(Call call);

};