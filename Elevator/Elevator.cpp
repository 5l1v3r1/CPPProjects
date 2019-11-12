#include <vector>
#include "Elevator.h"

Elevator::Elevator(unsigned int capacity) {
	this->capacity = capacity;
}

void Elevator::moveElevator(const unsigned int maxFloor) {

	currentFloor += direction;
	if(currentFloor >= maxFloor) {
		currentFloor = maxFloor;
		direction = down;
	} else if(currentFloor <= 0) {
		currentFloor = 0;
		direction = up;
	}

}

void Elevator::dropOffTargets() {

	for(int i = 0; i < targetFloors.size(); i++) {
		if(targetFloors[i] == currentFloor) {
			targetFloors.erase(targetFloors.begin() + i);
			i--;
		}
	}

}