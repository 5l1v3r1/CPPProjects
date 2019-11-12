#pragma once

enum directions { down = -1, indiff = 0, up = 1 };

class Elevator {

public:
	unsigned int capacity;
	unsigned int currentFloor = 0;
	std::vector<unsigned int> targetFloors;
	directions direction = up;

	Elevator(unsigned int capacity);

	void moveElevator(const unsigned int maxFloor);
	
	void dropOffTargets();

};