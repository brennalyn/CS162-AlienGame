
/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the ItemSpace class
 * which is a subclass of the Space class.
 **********************************************************************/

#ifndef ITEMSPACE_HPP
#define ITEMSPACE_HPP

#include "Space.hpp"

class ItemSpace : public Space {
	
	public:
		ItemSpace(string newName);
		virtual int enterRoom(vector<Item> &backpack);
		
};
#endif
