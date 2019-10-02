
#include <iostream>
#include <string>
#include <variant>

#define SENTINAL "exit"
#define TO_SOLVE "?"

bool getInput(std::variant<std::string, float>* toOut);
//Try to find better way to do this, psuedo define
bool qUsed = false;

int main(){

	std::string stringArr[4] = {
		"Width of the River",
		"Speed of the River",
		"Speed of the Boat",
		"Distance Downstream to the Boat Landing"
	};

	while(true){

		std::variant<std::string, float> varArr[4];

		for(int i = 0; i < 4; i++){

			std::cout << stringArr[i] << " :" << std::endl;
			if(!getInput(&varArr[i]))
				break;

		}

		if(!qUsed){
			
			std::cout << "You didn't define an unknown. You don't need my help on that one." << std::endl;
			continue;

		}
		
		for (int i = 0; i < 4; i++) {

			if(auto value = std::get_if<std::string>(&varArr[i])){
				std::cout << stringArr[i] << " : " << *value << std::endl;
			} else if(auto value = std::get_if<float>(&varArr[i])){
				std::cout << stringArr[i] << " : " << *value << " " << i << std::endl;
			}
			

		}

		//Solve

		//Display

	}

}

bool getInput(std::variant<std::string, float>* toOut){

	std::string userIn;
	std::cin >> userIn;

	if(userIn == SENTINAL)
		return false;
		//Invalid from for loop, find diff way

	try {

		*toOut = std::stof(userIn);

	} catch(std::invalid_argument) {
	
		if(userIn == TO_SOLVE && !qUsed){
			*toOut = TO_SOLVE;
			qUsed = true;
		} else {
			std::cout << "Invalid, please try again :" << std::endl;
			getInput(toOut);
		}

	}

	return true;

}