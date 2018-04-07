/*******************************************************************
 * Program Name: Portable Menu 
 * Author: Brenna Smith
 * Date: 1/15/2018
 * Description: This is an editable program for menus. It allows the
 * user to add options as needed then returns the user's choice
*******************************************************************/

#include "Menu.hpp"
#include "inputValid.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl; 


//Allows user to enter options that can be read and chosen from later on
//then returns that option's correlating number for selection.
int Menu::addOption(string output){
	options.push_back(output);
	int number = options.size();
	return number;
}

//Reads options out to user if there are any stored, options are 
// allocated to their position in vector + 1 
void Menu::displayOptions(string prompt){
	if (options.size() == 0){
		cout << "No options to display." << endl;
	} else {
		cout << endl;
		cout << prompt << endl;
	//	cout << "Please select one of the following: " << endl;
		for (int i = 0; i < options.size(); i++){
			cout << i + 1 << ": " << options[i] << endl;
		}
	}
	cout << endl;
}

void Menu::removeOptions() {
	while(options.size() > 0) {
		options.pop_back();
	}
}	

//Continues to ask user for an option within range then return the chosen #
int Menu::getChoice(){
	int choice = 0;
	 
	while (choice <= 0 || choice > options.size()) { 
		cout << "Please choose an option 1 - " << options.size() << ": ";	
		choice = validInt();	
		cout << endl;
	}
	
	return choice;
}  

string Menu::getString(string prompt){
	cout << prompt << endl;
	return validString();
}	


int Menu::getInt(string prompt){
	cout << prompt << endl;
	return validInt();
}	


/*
double Menu::getDouble(string prompt){
	
}
*/	 
