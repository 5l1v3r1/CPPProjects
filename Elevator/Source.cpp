//Manager
// ^ Stores floors and passengers, designates which elevator holds which tokens,
// if the others can switch direction
//Make Elevator class that can expand past 2 and 10 floors

#include <iostream>
#include <vector>

enum directions {down = -1, indiff = 0, up = 1};

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

struct Call {

	unsigned int FromFloor;
	unsigned int TargetFloor;

};

class ElevatorManager {

	public:
		unsigned int floors;

		ElevatorManager(unsigned int floors) {
			this->floors = floors;
		}

		void addElevator(Elevator toAdd) {
			elevators.push_back(toAdd);
		}

		void addElevator(unsigned int capacity = 10) {
			elevators.emplace_back(Elevator(capacity));
		}

		void StartElevatorSequence() {
			
			const int NumberOfElevators = elevators.size();
			bool TerminateSequence = false;

			std::vector<Call> callStack;

			while(!TerminateSequence) {
				
				//addToCallStack
				//Assume all are valid, though if diff is 0 it should be ok.
				while(true) {
				
					std::cout << "Would you like to add a new call? (Y/N) ";
					std::string userIn;
					std::cin >> userIn;

					if(userIn[0] == 'y'){					
						callStack.push_back(getNewCall());
					} else {
						break;
					}

				}
			
				//Indv elevator logic
				for(int i = 0; i < NumberOfElevators; i++){
					
					Elevator& curElevator = elevators[i];
					
					//TEMP
					std::cout << "Cur : " << curElevator.currentFloor << " + " << curElevator.direction << std::endl;

					// Move according to last turns direction
					curElevator.currentFloor = curElevator.currentFloor + curElevator.direction;
					if(curElevator.currentFloor >= floors){
						curElevator.currentFloor = floors;
						curElevator.direction = down;
					} else if(curElevator.currentFloor <= 0) {
						curElevator.currentFloor = 0;
						curElevator.direction = up;
					}

					//TEMP
					std::cout << "At floor " << curElevator.currentFloor << std::endl;

					// Drop off
					for(int j = 0; j < curElevator.targetFloors.size(); j++){
						if(curElevator.targetFloors[j] == curElevator.currentFloor){
							curElevator.targetFloors.erase(curElevator.targetFloors.begin() + j);
							j--;
						}
					}

					/*
					//TEMP
					for (int j = 0; j < curElevator.targetFloors.size(); j++) {
						std::cout << "Passenger : " << curElevator.targetFloors[j] << std::endl;
					}
					*/

					//Pick up
					for (int j = 0; j < callStack.size(); j++) {
						if (callStack[j].FromFloor == curElevator.currentFloor && findCallDir(callStack[j]) == curElevator.direction){

							curElevator.targetFloors.push_back(callStack[j].TargetFloor);
							callStack.erase(callStack.begin() + j);
							j--;

						}
					}

					/*
					//TEMP
					for (int j = 0; j < curElevator.targetFloors.size(); j++) {
						std::cout << "Passenger : " << curElevator.targetFloors[j] << std::endl;
					}
					*/

					// Calculate new direction
					if(curElevator.targetFloors.size() == 0){
						
						int favoredDir = 0;
						for(auto e : elevators){
							favoredDir += e.direction;
						}

						if(favoredDir > 0){
							curElevator.direction = down;
						} else if(favoredDir < 0) {
							curElevator.direction = up;
						} else {
						
							int callsBelow = 0, callsAbove = 0;
							for(int i = 0; i < callStack.size(); i++){
								if(callStack[i].FromFloor >= curElevator.currentFloor){
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

					//TEMP
					for (int j = 0; j < curElevator.targetFloors.size(); j++) {
						std::cout << "Passenger : " << curElevator.targetFloors[j] << std::endl;
					}
					std::cout << curElevator.direction << std::endl;

				}

				//TEMP
				std::cout << "0 to Cont? ";
				std::cin >> TerminateSequence;

			}

			//StopElevatorSequence

		}

		Call getNewCall(){
			
			Call toRet;

			//Add in security checks for invalid values.
			std::cout << "Enter the passengers current floor. ";
			std::cin >> toRet.FromFloor;

			std::cout << "Enter the passengers target floor. ";
			std::cin >> toRet.TargetFloor;

			return toRet;

		}

	private:
		std::vector<Elevator> elevators;

		directions findCallDir(Call call){
			if(call.TargetFloor - call.FromFloor > 0){
				return up;
			} else {
				return down;
			}
		}

};

int main() {

	ElevatorManager manager = ElevatorManager(9);
	manager.addElevator();
	//manager.addElevator();
	manager.StartElevatorSequence();

	std::cin.get();

}

/*
10 floors
Graphic print out
Don't switch direction until all request are satisfied
Only pick up passengers going in the same direction
*/
