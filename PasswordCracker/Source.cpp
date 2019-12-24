#include <iostream>
#include <string>
#include "Cracker.h"

/*
	Store user password
	You must include all letters lower and upper case, and the following characters: !@#$%^&*()_
	Create threaded program to brute force crack the password
	Optional print out current password
	Optimize to hell

	Add in some profiling to keep track of time, Cherno
*/

int incrementString(std::string& toEdit, int index);

std::string crackPassword(std::string password, bool logActivity, bool logTime) {

	std::cout << "Starting Crack" << std::endl;

	// Log Time

	// Change max size based on if we can know the length
	int maxSize = 5;
	
	for(int i = 1; i <= maxSize; i++){

		std::string toRet = std::string(i, '!');
		
		while(toRet != std::string(i, '~')){

			incrementString(toRet, i);

			if(logActivity)
				std::cout << toRet << std::endl;

			if(password == toRet)
				return "The password is : " + toRet;

		}

	}

	return "Could not crack :(";

}

// Prototype, I'd rather this use individual chars than whole strings
int incrementString(std::string& toEdit, int index) {

	if(index < 0) {
		return 1;
	}

	toEdit[index] += incrementString(toEdit, index - 1);

	// ASCII range for all chars 33 - 126 perhaps take some characters out
	if(toEdit[index] > 126) {
		toEdit[index] = 33;
		return 1;
	} else {
		return 0;
	}

}

int main() {

	bool cont;

	do {

		std::string password;
		bool logActivity;
		bool logTime;

		// These will be sanitized later

		std::cout << "Please enter the password : ";
		std::cin >> password;
		std::cout << "Would you like to log the activity? ";
		std::cin >> logActivity;
		std::cout << "Would you like to log time? ";
		std::cin >> logTime;

		std::cout << "Cracking the password : " << password << std::endl << std::endl;

		std::cout << crackPassword(password, logActivity, logTime) << std::endl;

		std::cout << std::endl << "Crack another password? (0/1) ";
		std::cin >> cont;

	} while(cont);

}