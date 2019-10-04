
#include <iostream>
#include <string>
#include <variant>

#include <typeinfo>

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

	//Welcome text, use positive numbers for appropriate

	while(true){

		std::variant<std::string, float> varArr[4];
		int solvedIndex;
		float solvedVar;

		for(int i = 0; i < 4; i++){

			std::cout << stringArr[i] << " :" << std::endl;
			if(!getInput(&varArr[i]))
				break;

		}

		if(!qUsed){
			
			std::cout << "You didn't define an unknown. You don't need my help on that one." << std::endl;
			continue;

		}
		
		for(int i = 0; i < 4; i++) {

			if(auto value = std::get_if<std::string>(&varArr[i])){
				solvedIndex = i;
				//std::cout << stringArr[i] << " : " << *value << " " << i << std::endl;
				//[3] = [1]([0][2])
				
				if (i = 0) {
					solvedVar = (std::get<float>(varArr[3]) / std::get<float>(varArr[1])) / std::get<float>(varArr[2]);
				} else if (i = 1) {
					solvedVar = std::get<float>(varArr[3]) / (std::get<float>(varArr[0]) * std::get<float>(varArr[2]));
				} else if (i = 2) {
					solvedVar = (std::get<float>(varArr[3]) / std::get<float>(varArr[1])) / std::get<float>(varArr[0]);
				} else {
					solvedVar = std::get<float>(varArr[1]) * std::get<float>(varArr[0]) * std::get<float>(varArr[2]);
				}
				
				break;
			
			}
			/*else if(auto value = std::get_if<float>(&varArr[i])){
				//std::cout << stringArr[i] << " : " << *value << " " << i << std::endl;
			}*/
			
		}

		//Display

		std::cout << solvedVar << std::endl;
		std::cin;

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
		std::cout << "Type of " << typeid(std::stof(userIn)).name() << std::endl;

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