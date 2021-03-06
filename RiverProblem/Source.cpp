
#include <iostream>
#include <string>
#include <variant>

#define SENTINAL "exit"
#define TO_SOLVE "?"

bool getInput(std::variant<std::string, float>* toOut, bool* restart, bool* qUsed);

int main(){

	std::string stringArr[4] = {
		"Width of the River",
		"Speed of the River",
		"Speed of the Boat",
		"Distance Downstream to the Boat Landing"
	};

	std::string unitsArr[4] = {
		"(m)",
		"(m/s)",
		"(m/s)",
		"(m)"
	};

	//Welcome text, use positive numbers for appropriate
	
	std::cout << "Welcome to the river problem solver!" << std::endl << std::endl
		<< "Enter a \"?\" when you are promtped for the variable you'd like to solve for." << std::endl
		<< "If you mess up while entering variables simply type in \"exit\"." << std::endl << std::endl;

	while(true){

		std::variant<std::string, float> varArr[4];
		int solvedIndex;
		float solvedVar;
		bool qUsed = false;
		bool restart = false;

		for(int i = 0; i < 4; i++){

			std::cout << stringArr[i] << " " << unitsArr[i] << " : ";
			if(!getInput(&varArr[i], &restart, &qUsed))
				break;

		}

		if(restart){
			
			std::cout << std::endl;
			continue;
		
		}

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

		//Make the stringArr to lower.
		std::cout << std::endl << "The " + stringArr[solvedIndex] + " is equal to " << solvedVar 
			<< " " << unitsArr[solvedIndex] << std::endl << std::endl;
		
	}

}

bool getInput(std::variant<std::string, float>* toOut, bool* restart, bool* qUsed){

	std::string userIn;
	std::cin >> userIn;

	if(userIn == SENTINAL){
		*restart = true; 
		return false;
	}

	try {

		*toOut = std::stof(userIn);

	} catch(std::invalid_argument) {

		if(userIn == TO_SOLVE && !*qUsed){
			*toOut = TO_SOLVE;
			*qUsed = true;
		} else {
			std::cout << "\rInvalid, please try again : ";
			getInput(toOut, restart, qUsed);
		}

	}

	return true;

}
