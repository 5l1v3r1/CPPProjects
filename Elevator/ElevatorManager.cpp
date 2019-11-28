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

		drawSequence(elevators, callStack);

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
			std::cout << std::endl;
			break;
		}

		std::cout << std::endl;

	}

}

void ElevatorManager::drawSequence(std::vector<Elevator> elevators, std::vector<Call> callStack) {

	// In future the elevators may have more detail in which case.
	// more than `floors` will be needed.
	
	/*
		 Calls +--------------+ Elevators
		    
		From 2 to 7         10 | e1 | -- |
		From 6 to 8          9 | -- | -- |
		From 1 to 3          8 | -- | e2 |
		...
		From 1 to 4          0 | -- | -- |
		From 6 to 3            ===========
	*/

	std::string strCalls[floors];
	std::string strElevators[floors];

	int spaceForElevators = elevators.size() * 4 + elevators.size() + 1;
	int spaceForCalls = 9 + floor(log10(floors) + 1) * 2; // Chars and spaces + digits

	// Calls

	// Elevators

	// Printing
	std::cout << " Calls " << "+" << std::string(20, '-') << "+" 
	<< " Elevators" << std::endl << std::endl;

	for(int i = 0; i < floors; i++){
		std::cout << strCalls[i] << strElevators[i] << std::endl;
	}

}