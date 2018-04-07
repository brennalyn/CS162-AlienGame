

/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the EscapeSpace class
 * which is a subclass of the Space class. Only used for escape shuttle;
 **********************************************************************/

#include "EscapeSpace.hpp"
#include "inputValid.hpp"
#include <iostream>

using std::cout;
using std::endl;

//Set room name
EscapeSpace::EscapeSpace(string newName) {
	name = newName;
}	

//Entering this space sets off actons spacific to this space type
int EscapeSpace::enterRoom(vector<Item> &backpack) {

	int count = 0;

	//Check items to see if all 3 required ones have been collected
	for (int i = 0; i < backpack.size(); i++) {
		if (backpack[i] == comm || backpack[i] == shot || backpack[i] == cat) {
			count++;
		}	
	}	 

	cout << "You have " << count << " required items." << endl;

	//If they have everything
	if (escapeShip(backpack)) {
		cout << "You have everything you need to escape!" << endl;
		return 1;
	} else { 
		count = 3 - count;
		cout << "You still have " << count << " items to acquire." << endl; 
	}		

	return 0;
}
	
//See if you have everything you need to escape
bool EscapeSpace::escapeShip(vector<Item> backpack ) {
	int count = 0;
		
	for (int i = 0; i < backpack.size(); i++) {
		if (backpack[i] == comm || backpack[i] == shot || backpack[i] == cat) {
			count++;
		}	
	}	 

	return count == 3;		
	
}		

