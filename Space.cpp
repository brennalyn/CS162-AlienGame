
/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the implementation file for the abstract Space
 *  class that has several subclasses.
 **********************************************************************/

#include "Space.hpp"

//enum Item { comm, shot, cat, bandages, fuel, photo }; 

/*
Space* up;
Space* right;
Space* down;
Space* left;
*/		
		
Space::Space() {
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
	
}	

Space* Space::getUp() {
	return up; 
}
	
void Space::setUp(Space* newRoom) {
	Space* temp = this; 
	up = newRoom;

	if (newRoom->getDown() != temp) {
		newRoom->setDown(temp);
	}
}	

Space* Space::getDown() {
	return down;
}	

void Space::setDown(Space* newRoom) {
	Space* temp = this; 
	down = newRoom;
	
	if (newRoom->getUp() != temp) {
		newRoom->setUp(temp);
	}	
}	

Space* Space::getLeft() {
	return left;	
}		

void Space::setLeft(Space* newRoom) {
	Space* temp = this; 
	left = newRoom;
	if (newRoom->getRight() != temp) {
		newRoom->setRight(temp);
	}
}	

Space* Space::getRight() {
	return right;
}	


void Space::setRight(Space* newRoom) {
	Space* temp = this; 
	right = newRoom;
	if (newRoom->getLeft() != temp) {
		newRoom->setLeft(temp);
	}
}	

string Space::getName() {
	return name;
}	
	
