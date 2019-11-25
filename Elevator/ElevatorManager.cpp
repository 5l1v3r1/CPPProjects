#include "ElevatorManager.h"

ElevatorManager::ElevatorManager(unsigned int floors) {
	this->floors = floors;

	std::cout << "Welcome to your new elevator manager." << std::endl << std::endl;

}

void ElevatorManager::addElevator(Elevator toAdd) {
	elevators.push_back(toAdd);
}

void ElevatorManager::addElevator(unsigned int capacity) {
	elevators.emplace_back(Elevator(capacity));
}

void ElevatorManager::startElevatorSequence() {

	if(elevators.size() <= 0) {
		std::cout << "Error, You have not made any elevators." << std::endl;
		return;
	}

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
			
			curElevator.moveElevator(floors);
			curElevator.dropOffTargets();
			curElevator.pickUpTargets(callStack);
			if(curElevator.changeDirection(favoredDirection))
				curElevator.pickUpTargets(callStack);

		}

		//TEMP
		std::cout << std::endl << "Continue sequence? (1/0) ";
		std::cin >> TerminateSequence;
		TerminateSequence = !TerminateSequence;
		//ENDTEMP

	}

}

void ElevatorManager::addToCallStack(std::vector<Call>& callStack) {

	while(true) {

		std::cout << "Would you like to add a new call? (Y/N) ";
		std::string userIn;
		std::cin >> userIn;

		if(userIn[0] == 'y') {

			Call toAdd;
			unsigned int hold;

			//In this case goto could be useful.
			//Also allow to break from here.
			//Look into optimizing these and creating functions as I think these could be used elsewhere.
			//Format the output of the lines to be more friendly to look at
			std::cout << "Enter the passengers current floor";
			while((std::cout << " : ") && !(std::cin >> hold) || hold < 1 || hold > floors) {

				std::cout << "That is not a valid floor.\nEnter a floor between "
				<< 1 << " and " << floors;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			toAdd.FromFloor = hold;

			//Add special message for inputing same target floor as the from floor.
			std::cout << "Enter the passengers target floor";
			while((std::cout << " : ") && !(std::cin >> hold) || hold < 1 || hold > floors
			|| hold == toAdd.FromFloor) {

				std::cout << "That is not a valid floor.\nEnter a floor between "
				<< 1 << " and " << floors;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			}
			toAdd.TargetFloor = hold;

			callStack.emplace_back(toAdd);

		} else {
			break;
		}

		std::cout << std::endl;

	}

}
