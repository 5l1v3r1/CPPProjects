
#include <iostream>
#include <string>
#include <variant>

#define SENTINAL "exit"
#define TO_SOLVE "?"

bool getInput(std::variant<std::string, float>* toOut);
//Try to find better way to do this, psuedo define
bool qUsed;
bool restart = false;

int main(){

	std::string stringArr[4] = {
		"Width of the River",
		"Speed of the River",
		"Speed of the Boat",
		"Distance Downstream to the Boat Landing"
	};

	//Welcome text, use positive numbers for appropriate

	while(true){

		std::variant<std::string, float> varArr[4];
		int solvedIndex;
		float solvedVar;
		qUsed = false;
		restart = false;

		for(int i = 0; i < 4; i++){

			std::cout << stringArr[i] << " :" << std::endl;
			if(!getInput(&varArr[i]))
				break;

		}

		if(restart)
			continue;

		if(!qUsed){
			
			std::cout << "You didn't define an unknown. You don't need my help on that one." << std::endl;
			continue;

		}
		
		for(int i = 0; i < 4; i++) {

			if(auto value = std::get_if<std::string>(&varArr[i])){

				solvedIndex = i;

				auto value0 = std::get_if<float>(&varArr[0]);
				auto value1 = std::get_if<float>(&varArr[1]);
				auto value2 = std::get_if<float>(&varArr[2]);
				auto value3 = std::get_if<float>(&varArr[3]);

				if(i == 0) {
					solvedVar = (*value3 / *value1) * *value2;
				} else if (i == 1) {
					solvedVar = *value3 / (*value0 / *value2);
				} else if (i == 2) {
					solvedVar = *value0 / (*value3 / *value1);
				} else {
					solvedVar = *value1 * (*value0 / *value2);
				}
				
				break;
			
			}
			
		}

		//Display

		std::cout << solvedVar << std::endl;
		std::cin;

	}

}

bool getInput(std::variant<std::string, float>* toOut){

	std::string userIn;
	std::cin >> userIn;

	if(userIn == SENTINAL){
		restart = true; 
		return false;
	}
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