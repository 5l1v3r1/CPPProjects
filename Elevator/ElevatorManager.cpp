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

		addToCallStack(callStack);

		int favoredDirection = 0;
		for(auto e : elevators) {
			favoredDirection += e.direction;
		}

		//Indv Elevator logic
		for(int i = 0; i < NumberOfElevators; i++) {

			Elevator& curElevator = elevators[i];
			
			//std::cout << "Elevator dir " << curElevator.direction << "    " << favoredDirection << std::endl;

			curElevator.moveElevator(floors);
			curElevator.dropOffTargets();
			curElevator.pickUpTargets(callStack);
			if(curElevator.changeDirection(favoredDirection))
				curElevator.pickUpTargets(callStack);

			//std::cout << "Elevator dir " << curElevator.direction << "    " << favoredDirection << std::endl;

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
