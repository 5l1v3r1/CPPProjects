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

void Elevator::pickUpTargets(std::vector<Call>& callStack){

	for(int j = 0; j < callStack.size(); j++) {
		if(callStack[j].FromFloor == currentFloor && findCallDir(callStack[j]) == direction) {

			targetFloors.push_back(callStack[j].TargetFloor);
			callStack.erase(callStack.begin() + j);
			j--;

		}
	}

}