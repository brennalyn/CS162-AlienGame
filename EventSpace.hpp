

/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the Event Space
 *  class that is subclass of the Space class.
 **********************************************************************/

#ifndef EVENTSPACE_HPP
#define EVENTSPACE_HPP

#include "Space.hpp"
//#include <string>


class EventSpace : public Space {
	
	public:	
		EventSpace(string newName);
		virtual int enterRoom(vector<Item> &backpack);
		
};
#endif
