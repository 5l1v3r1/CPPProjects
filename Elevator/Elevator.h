#pragma once

enum directions { down = -1, indiff = 0, up = 1 };

class Elevator {

public:
	unsigned int capacity;
	unsigned int currentFloor;
	std::vector<unsigned int> targetFloors;
	directions direction = indiff;

	Elevator(unsigned int capacity);

};