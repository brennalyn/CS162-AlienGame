
/**********************************************************************
** Program Name: Input Validation 
** Author: Brenna Smith
** Date: 01/25/2018
** Description: This file holds the input validation for Ints and Char 
 ***********************************************************************/

#include "inputValid.hpp"
#include <string>
#include <iostream>
#include <ios>
#include <limits>

using std::string;
//using std::stoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::streamsize;
using std::numeric_limits;

//enum inputData {wholeNum, character};
/*
string chooseType(inputData choice){
	string validated;
	if (choice = wholeNum){
		validated = validInt();
	} else if (choice = character){
		validated = validChar();
	}


	return validated;
}
*/


int validInt(){
	string entry;
	bool isInt, negInt; 
	
			
	do {
		isInt = true;
		negInt = false;
		 
		cin >> entry;
		//Found this line after researching at https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ 
		cin.ignore(numeric_limits<streamsize>::max(),'\n');	
	
		//Checks for negative sign
		if(entry.at(0) == 45){
			entry.erase(entry.begin());
			negInt = true;
		}

		//Checks the input for any non-numerics including spaces
		for(int i = 0; i < entry.length(); i++){
			if(entry.at(i) > 57 || entry.at(i) < 48){
				isInt = false; 
			}
		}

		if(!isInt){
			cout << "Not a valid integer, please try again." << endl;
		}
	
	} while(!isInt);

	int value = stoi(entry, nullptr);

	//Multiplies the result by -1 if it was found to be negative input
	if(negInt){
		value *= -1;
	}

	return value;
}


double validDouble(){
	string entry;
	bool isFloat, negFloat, decPoint; 
		
			
	do {
		isFloat = true;
		negFloat = false;
		decPoint = false;
		
		cin >> entry;
		//Found this line after researching at https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ 
		cin.ignore(numeric_limits<streamsize>::max(),'\n');	
	
		//Checks for negative sign
		if(entry.at(0) == 45){
			entry.erase(entry.begin());
			negFloat = true;
		}

		//Checks the input for any non-numerics including spaces
		for(int i = 0; i < entry.length(); i++){
			//Check for 1 decimal point. If this is a 2nd dec point then not valid
			if(entry.at(i) == 46 && !decPoint){
				decPoint = true;
			} else {	
				if(entry.at(i) > 57 || entry.at(i) < 48){
					isFloat = false; 
				}
			}	
		}

		if(!isFloat){
			cout << "Not a valid decimal number, please try again." << endl;
		}
	
	} while(!isFloat);

	double value = stod(entry, nullptr);

	//Multiplies the result by -1 if it was found to be negative input
	if(negFloat){
		value *= -1;
	}

	return value;
}


char validChar(){
	bool valid = false;
	string input = "";
	char choice;
	//repeat until valid single letter is entered
	while (!valid){
		
//		cout << "Please enter a single letter." << endl;		
	
		getline(cin, input);
		choice  = input.at(0);
		
		//Check that the input is alphabetic and that there is only 1 char
		if (isalpha(choice) && input.length() == 1){
			valid = true;
		} else {
			cout << "Not a valid character. Try again." << endl;
		}
	}

	return tolower(choice);
}

string validString(){
	bool valid = false;
	string input = "";

	while (!valid) {
		
		getline(cin, input);

		if (input != "" && input.at(0) != ' '){
			//getline(cin, input);
			valid = true;	
			
		} else {
			cout << "Please enter a valid string." << endl;
		}
	}	

	return input;
}	
	


