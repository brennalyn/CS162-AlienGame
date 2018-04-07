

/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the EscapeSpace class
 * which is a subclass of the Space class. Only used for escape shuttle;
 **********************************************************************/

#ifndef ESCAPESPACE_HPP
#define ESCAPESPACE_HPP

#include "Space.hpp"

class EscapeSpace : public Space {

	public:
		EscapeSpace(string newName);
		virtual int enterRoom(vector<Item> &backpack);
		bool escapeShip(vector<Item> backpack);	
};
#endif
