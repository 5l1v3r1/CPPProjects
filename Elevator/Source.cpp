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
			elevators.push_back(Elevator(capacity));
		}

		void StartElevatorSequence() {
			
			const int NumberOfElevators = elevators.size();
			bool TerminateSequence = false;

			std::vector<Call> callStack;

			while(!TerminateSequence) {
				
				//addToCallStack

				for(int i = 0; i < NumberOfElevators; i++){
					
					Elevator curElevator = elevators[i];
					
					// Move according to last turns direction
					curElevator.currentFloor = curElevator.currentFloor + curElevator.direction > floors ?
						floors : curElevator.currentFloor + curElevator.direction;

					// Drop off

					//Pick up

					// Calculate new direction

				}

			}

			//StopElevatorSequence

		}

	private:
		std::vector<Elevator> elevators;

};

int main() {

	ElevatorManager manager = ElevatorManager(10);
	manager.addElevator();
	manager.addElevator();



}

/*
10 floors
Graphic print out
Don't switch direction until all request are satisfied
Only pick up passengers going in the same direction
*/
