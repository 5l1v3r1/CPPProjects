#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Cracker.h"

#define timepoint std::chrono::_V2::system_clock::time_point

std::string determineTimeDifference(timepoint timeOne) {

	std::string toRet = "Cracking took : ";

	auto timeTwo = std::chrono::high_resolution_clock::now();
	auto durationS = 
		std::chrono::duration_cast<std::chrono::seconds>(timeTwo - timeOne).count();
	auto durationMS = 
		std::chrono::duration_cast<std::chrono::milliseconds>(timeTwo - timeOne).count();

	if(durationS > 0) {
		toRet += std::to_string(durationS) + " seconds and ";
		durationMS = durationMS % 1000;
		if(durationMS > 0)
			toRet += std::to_string(durationMS) + " milliseconds.";
	} else 
		toRet += std::to_string(durationMS) + " milliseconds.";

	return toRet;

}

int incrementString(std::string& toEdit, int index);
void threadCrack(std::string password, bool& done, int startIndex, int endIndex, bool logActivity);

std::string crackPassword(std::string password, bool logActivity, bool logTime) {

	std::cout << "Starting Crack" << std::endl;

	timepoint timeOne;
	if(logTime)
		timeOne = std::chrono::high_resolution_clock::now();

	bool cracked;
	std::thread threads[8];

	// Needs a better way to delegate sections of the password.
	// Need a better way to stop threads and find the if it's been cracked
	for(int i = 0; i < 8; i++) {
		threads[i] = std::thread(threadCrack, password, std::ref(cracked), 0, 0, logActivity);
	}

	while(!cracked) {}
	for(int i = 0; i < 8; i++)
		threads[i].join();

	if(logTime)
		std::cout << determineTimeDifference(timeOne) << std::endl;

	return password;

}

void threadCrack(std::string password, bool& done, int startIndex, int endIndex, bool logActivity) {

	// Change max size based on if we can know the length
	int maxSize = 5;
	
	for(int i = 1; i < maxSize; i++){

		std::string toRet = std::string(i, '!');
		
		while(toRet != std::string(i, '~')){

			incrementString(toRet, i);

			if(logActivity)
				std::cout << toRet << std::endl;

			if(password == toRet) {
				done = true;
				return;
			}

		}

	}

	std::cout << "Thread Failed\n";

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

bool getBoolInput(std::string message) {

	std::string hold;

	while(true) {
		
		std::cout << message << " (1/0) : ";
		std::cin >> hold;
		if(hold == "1" || std::tolower(hold[0]) == 'y')
			return true;
		else if(hold == "0" || std::tolower(hold[0]) == 'n')
			return false;
		else
			std::cout << "Please enter a valid boolean." << std::endl;

	}

}

int main() {

	bool cont;

	do {

		std::string password;
		bool logActivity;
		bool logTime;

		std::cout << "Please enter the password (current max is 5 characters) : ";
		std::cin >> password;
		
		logActivity = getBoolInput("Would you like to log the activity?");
		logTime = getBoolInput("Would you like to log time?");

		std::cout << "Cracking the password : " << password << std::endl << std::endl;

		std::cout << crackPassword(password, logActivity, logTime) << std::endl << std::endl;

		cont = getBoolInput("Crack another password?");

	} while(cont);

}