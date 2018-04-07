

/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the Event Space
 *  class that is subclass of the Space class.
 **********************************************************************/

#include "EventSpace.hpp"
#include "inputValid.hpp"
#include <iostream>

using std::cout;
using std::endl;

EventSpace::EventSpace(string newName) {
	name = newName;
}	

int EventSpace::enterRoom(vector<Item> &backpack) {
	int encounter = rand() % 5;
	int damage = 0;
	char answer = ' ';

	if (encounter == 0) { 
		cout << "You walk into the room and everything is quiet." << endl;
		cout << "You search around for items but find nothing until you reach a cabinet." << endl;
		cout << "You open the cabinet to find a ..." << endl;
		cout << "FACEHUGGER!" << endl;
		cout << "You battle with it as it tries to wrap around your throat, but are able to " << endl;
		cout << "grasp a sharp object to stab it with." << endl;
		cout << "You lose 3 health as the acid blood splashes onto your arm." << endl;   
		damage = -3;

	} else if (encounter == 1) {
		cout << "You duck into the next room and perform a quick scan. Nothing. Finally, a moment to rest." << endl;

	} else if (encounter == 2) {
		cout << "You walk into the room. Everything is quiet." << endl;
		cout << "You find a closed cabinet. You open the cabinet and find a ... " << endl;
		cout << "bottle of painkillers! You regain 5 health." << endl;
		damage = 5;

	} else if (encounter == 3) {	
		cout << "You duck into the next room and perform a quick scan. Nothing. "<< endl; 
		cout << "You go to sit down but something is missing. You check your equipment. Blast! You dropped an item!" << endl;
		int item = (rand() % (backpack.size() - 1)) + 1;
		backpack.erase(backpack.begin() + item);

	} else {
		cout << "You walk into the room and start searching. You find an apple and sit down to regain energy." << endl; 
		cout << "You regain 3 health." << endl; 
		damage = 3;	
	}		

	return damage;
}
