#include "Elevator.h"

Elevator::Elevator(unsigned int capacity) {
	this->capacity = capacity;
}

void Elevator::moveElevator(const unsigned int maxFloor) {

	currentFloor += direction;
	if(currentFloor >= maxFloor) {
		currentFloor = maxFloor;
		direction = down;
	} else if(currentFloor <= 1) {
		currentFloor = 1;
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

	for(int i = 0; i < callStack.size(); i++) {
		if (callStack[i].FromFloor == currentFloor && getCallDir(callStack[i]) == direction) {

			targetFloors.push_back(callStack[i].TargetFloor);
			callStack.erase(callStack.begin() + i);
			i--;

		}
	}

}

//Returns true if the direction was changed.
bool Elevator::changeDirection(int& favouredDirection, std::vector<Call>& callStack) {

	if(targetFloors.size() > 0)
		return false;

	int callsAbove = 0, callsBelow = 0;
	int closestCallA = std::numeric_limits<int>::max();
	int closestCallB = std::numeric_limits<int>::min();

	for(auto call : callStack) {

		if(call.FromFloor > currentFloor) {
			callsAbove++;
			if(call.FromFloor < closestCallA)
				closestCallA = call.FromFloor;
		} else {
			callsBelow++;
			if(call.FromFloor > closestCallB)
				closestCallB = call.FromFloor;
		}

	}
	
	if(callsAbove > callsBelow) {
		direction = up;
		targetFloor = closestCallA;
	} else {
		direction = down;
		targetFloor = closestCallB;
	}
	if(callsAbove == 0 && callsBelow == 0)
		direction = indiff;

	return true;

}