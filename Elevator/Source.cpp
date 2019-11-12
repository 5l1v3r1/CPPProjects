//Manager
// ^ Stores floors and passengers, designates which elevator holds which tokens,
// if the others can switch direction
//Make Elevator class that can expand past 2 and 10 floors

#include <iostream>
#include <vector>
#include "ElevatorManager.h"
#include "Elevator.h"

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
