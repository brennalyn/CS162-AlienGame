
/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the Alien Space
 *  class that is subclass of the Space class.
 **********************************************************************/

#ifndef ALIENSPACE_HPP
#define ALIENSPACE_HPP

#include "Space.hpp"
//#include <string>


class AlienSpace : public Space {
	
	public:
		AlienSpace(string newName);
		virtual int enterRoom(vector<Item> &backpack);
		
};
#endif
