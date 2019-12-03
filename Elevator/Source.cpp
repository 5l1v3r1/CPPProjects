#include <iostream>
#include <vector>
#include "ElevatorManager.h"
#include "Elevator.h"
#include "Call.h"

int main() {

	ElevatorManager manager = ElevatorManager(10);
	manager.addElevator();
	//manager.addElevator();
	manager.startElevatorSequence();

}