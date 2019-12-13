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

void crackChar(std::string& toEdit, std::string password, int index, bool logActivity);

std::string crackPassword(std::string password, bool logActivity, bool logTime) {

	std::cout << "Starting Crack" << std::endl;

	int maxSize = 5;
	// Test to make sure editing higher indices works
	std::string toRet = "";

	// ASCII range for all chars 33 - 126 perhaps take some characters out
	// Not sure if this should access the length or not

	int curSize = maxSize;

	// Loops through the chars of that length

	// TODO Fix out of range
	for (int i = 0; i <= curSize - 1; i++) {
	
		std::cout << "Testing" << std::endl;
		crackChar(toRet, password, i, logActivity);

	}

	return "Could not crack :(";

}

void crackChar(std::string& toEdit, std::string password, int index, bool logActivity) {

	// Checks with each ascii value
	for(int asc = 33; asc <= 126; asc++) {

		toEdit[index] = (char)asc;

		if(logActivity)
			std::cout << toEdit << std::endl;

		if(toEdit == password) {
			// return true for break
		}

	}

}

int main() {

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

	// TEMP
	std::cout << crackPassword(password, true, false);
	std::cin >> logTime;

}