//Manager
// ^ Stores floors and passengers, designates which elevator holds which tokens,
// if the others can switch direction
//Make Elevator class that can expand past 2 and 10 floors

#include <iostream>
#include <vector>
#include "ElevatorManager.h"
#include "Elevator.h"
#include "Call.h"

int main() {

	ElevatorManager manager = ElevatorManager(9);
	//manager.addElevator();
	//manager.addElevator();
	//manager.startElevatorSequence();
	/*
	Elevator testElev = Elevator(5);
	testElev.currentFloor = 3;
	testElev.direction = up;
	testElev.targetFloors.push_back(4);
	testElev.targetFloors.push_back(2);
	testElev.targetFloors.push_back(6);
	testElev.targetFloors.push_back(4);

	testElev.moveElevator(9);
	testElev.dropOffTargets();
	
	std::vector<Call> callStack;
	manager.addToCallStack(callStack);
	testElev.pickUpTargets(callStack);

	for(int i = 0; i < testElev.targetFloors.size(); i++){
		std::cout << testElev.targetFloors[i] << " break" << std::endl;
	}
	std::cout << " Callstack ::" << std::endl;
	for(int i = 0; i < callStack.size(); i++) {
		std::cout << callStack[i].FromFloor << " break" << std::endl;
	}
	*/

}

/*
10 floors
Graphic print out
Don't switch direction until all request are satisfied
Only pick up passengers going in the same direction
*/
