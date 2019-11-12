#include <vector>
#include "Elevator.h"

class Elevator {

public:
	unsigned int capacity;
	unsigned int currentFloor = 0;
	std::vector<unsigned int> targetFloors;
	directions direction = indiff;

	Elevator(unsigned int capacity) {
		this->capacity = capacity;
	}

};