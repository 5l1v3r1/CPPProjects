
#include <iostream>
#include <string>

#define SENTINAL "exit"

bool getInput(float *toOut);

int main(){

	while(true){
		
		//Setup the vars for problems, Array?
		float var1;

		//Loop through vars
		if(!getInput(&var1))
			break;

		//Solve
		std::cout << var1 << std::endl;

		//Display

	}

}

bool getInput(float *toOut){

	std::string userIn;
	std::cin >> userIn;

	if(userIn == SENTINAL)
		return false;

	//Add try for bad input
	*toOut = std::stof(userIn);

	return true;

}