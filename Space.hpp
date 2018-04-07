
/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the abstract Space
 *  class that has several subclasses.
 **********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

enum Item { empty, half, full, comm, shot, cat, bandages, fuel, adrenaline }; 

class Space {

        protected:
		Space* up;
		Space* right;
		Space* down;
		Space* left;
		string name;
				
	public:
		Space();
		Space* getUp();
		void setUp(Space* newRoom);
		Space* getDown();
		void setDown(Space* newRoom);
		Space* getLeft();
		void setLeft(Space* newRoom);	
		Space* getRight();
		void setRight(Space* newRoom);
		string getName();
		

		virtual int enterRoom(vector<Item> &backpack) = 0;
	
};
#endif
