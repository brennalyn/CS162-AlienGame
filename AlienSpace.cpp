
/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the Alien Space
 *  class that is subclass of the Space class.
 **********************************************************************/

#include "AlienSpace.hpp"
#include "inputValid.hpp"
#include <iostream>

using std::cout;
using std::endl;

AlienSpace::AlienSpace(string newName) {
	name = newName;
}	

int AlienSpace::enterRoom(vector<Item> &backpack) {
	int encounter = rand() % 3;
	int damage = 0;
	char answer = ' ';

	//randomize a type of alien attack
	if (encounter == 0) { 
		cout << "A hiss of air from behind forces you to spin and look up as the " << endl;
		cout << "alien bears down on you from the shadows, its dripping fangs glistening." << endl;

	} else if (encounter == 1) {
		cout << "A nearby vent crashes to the floor as the alien lunges through to ensnare you in its pitch black talons." << endl;

	} else {

		cout << "You nearly fall as the grate below you buckles upwards, "<< endl;
		cout << "the alien's black barbed tail smashing through to wrap around your leg." << endl;
		
	}		

	//If the user has fuel, let them decide whether or not to use flamethrower 
	if (backpack[0] != empty) {
		cout << "Would you like to use your flamethrower to defend yourself? " ;	
		while (answer != 'y' && answer != 'n') { 
			cout << "Y or N?" << endl;
			answer = validChar();
		}	
	} else {
		cout << "Your flamethrower is out of fuel!" << endl;	
	}		 

	//Randomize damage based on whether or not user used flamethrower
	if (answer == 'y') {
		//With flamethrower the alien does 0-5 damage
		damage = rand() % 6;
		if (backpack[0] == full) {
			backpack[0] = half;
		} else {
			backpack[0] = empty;	
		}
		cout << "You scare the alien away with the flames and get away with "<< damage << "damage." << endl;  		
	} else {
		//If no flamethrower the alien does 5-10 damage
		damage = (rand() % 5) + 5;
		cout << "You try to run, but aren't fast enough as the alien deals " << damage << "damage." << endl; 
	}		

	damage *= -1;

	return damage;
}	
