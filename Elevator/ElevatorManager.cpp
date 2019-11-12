#include <vector>
#include <iostream>
#include "Elevator.h"
#include "ElevatorManager.h"

ElevatorManager::ElevatorManager(unsigned int floors) {
	this->floors = floors;
}

void ElevatorManager::addElevator(Elevator toAdd) {
	elevators.push_back(toAdd);
}

void ElevatorManager::addElevator(unsigned int capacity = 10) {
	elevators.emplace_back(Elevator(capacity));
}

void ElevatorManager::startElevatorSequence() {

	const int NumberOfElevators = elevators.size();
	bool TerminateSequence = false;

	std::vector<Call> callStack;

	while(!TerminateSequence) {

		//Calc and stored favoured dir

		//Indv Elevator logic
		for(int i = 0; i < NumberOfElevators; i++) {

			Elevator& curElevator = elevators[i];
			
			curElevator.moveElevator(floors);
			curElevator.dropOffTargets();

		}

		//TEMP
		std::cout << "Continue sequence? (1/0) ";
		std::cin >> TerminateSequence;
		TerminateSequence = !TerminateSequence;
		//ENDTEMP

	}

}

void ElevatorManager::addToCallStack(std::vector<Call>& callStack) {

	//Assume all are valid, though if diff is 0 it should be ok.
	while(true) {

		std::cout << "Would you like to add a new call? (Y/N) ";
		std::string userIn;
		std::cin >> userIn;

		if(userIn[0] == 'y') {

			Call toAdd;

			//Add in security checks for invalid values.
			//In this case goto could be useful.
			//Also allow to break from here.
			std::cout << "Enter the passengers current floor. ";
			std::cin >> toAdd.FromFloor;

			std::cout << "Enter the passengers target floor. ";
			std::cin >> toAdd.TargetFloor;

			callStack.emplace_back(toAdd);

		} else {
			break;
		}

	}

}

directions ElevatorManager::findCallDir(Call call) {

	if(call.TargetFloor - call.FromFloor > 0) {
		return up;
	} else {
		return down;
	}

}

// FINISH REFACTOR
/*

			//Pick up
				for (int j = 0; j < callStack.size(); j++) {
					if (callStack[j].FromFloor == curElevator.currentFloor && findCallDir(callStack[j]) == curElevator.direction) {

						curElevator.targetFloors.push_back(callStack[j].TargetFloor);
						callStack.erase(callStack.begin() + j);
						j--;

					}
				}

				// Calculate new direction
				if (curElevator.targetFloors.size() == 0) {

					int favoredDir = 0;
					for (auto e : elevators) {
						favoredDir += e.direction;
					}

					if (favoredDir > 0) {
						curElevator.direction = down;
					} else if (favoredDir < 0) {
						curElevator.direction = up;
					} else {

						int callsBelow = 0, callsAbove = 0;
						for (int i = 0; i < callStack.size(); i++) {
							if (callStack[i].FromFloor >= curElevator.currentFloor) {
								callsAbove++;
							} else {
								callsBelow++;
							}
						}

						curElevator.currentFloor = callsAbove >= callsBelow ? up : down;

					}

				}

			//Recheck current floor
				for (int j = 0; j < callStack.size(); j++) {
					if (callStack[j].FromFloor == curElevator.currentFloor && findCallDir(callStack[j]) == curElevator.direction) {

						curElevator.targetFloors.push_back(callStack[j].TargetFloor);
						callStack.erase(callStack.begin() + j);
						j--;

					}
				}



*/