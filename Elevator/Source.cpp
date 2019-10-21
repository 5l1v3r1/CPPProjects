//Manager
// ^ Stores floors and passengers, designates which elevator holds which tokens,
// if the others can switch direction
//Make Elevator class that can expand past 2 and 10 floors

#include <iostream>
#include <vector>

int main() {

	std::cout << "Hello";

}

class ElevatorManager {

	public:
		unsigned int floors;
		//Make array :(;
		std::vector<bool> tokens;

		ElevatorManager(unsigned int floors) {
			this->floors = floors;
		}

		void addElevator(Elevator toAdd) {
			elevators.push_back(toAdd);
		}

		void addElevator(unsigned int capacity) {
			elevators.push_back();
		}

		bool passToken(unsigned int elevatorNum, unsigned int floorNum) {

			floorNum = floorNum < floors ? floorNum : floors;
			if(tokens[floorNum]) {
				tokens[floorNum] = false;
				return true;
			}
				return false;

		}

	private:
		std::vector<Elevator> elevators;

};

class Elevator {

	public:
		unsigned int capacity;

		Elevator(unsigned int capacity) {
			this->capacity = capacity;
		}

};

/*
10 floors
Graphic print out
Don't switch direction until all request are satisfied
Only pick up passengers going in the same direction
*/
