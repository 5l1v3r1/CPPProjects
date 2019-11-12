#pragma once

struct Call {

	unsigned int FromFloor;
	unsigned int TargetFloor;

};

class ElevatorManager {

public:
	unsigned int floors;

	ElevatorManager(unsigned int floors);

	void addElevator(Elevator toAdd);

	void addElevator(unsigned int capacity = 10);

	void StartElevatorSequence();

	Call getNewCall();

private:
	std::vector<Elevator> elevators;

	directions findCallDir(Call call);

};