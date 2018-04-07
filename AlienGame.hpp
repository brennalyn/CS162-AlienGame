

/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class header file for the lien game class
 * where most of the game functions lie.
 **********************************************************************/

#ifndef ALIENGAME_HPP
#define ALIENGAME_HPP

#include "Space.hpp"
#include <vector>
#include <string>

using std::vector;
using std::string;

class AlienGame {

        protected:
		vector<Item> backpack;
		int health;
		int timer;
		Space* current;
		Space* shuttle;
		bool gameOver;
		void setup();
		Space* randomType(string newName);
				
	public:
		AlienGame();
		~AlienGame();
		void move();
		void leaveRoom();
		void printShip();
		bool getStatus();
};
#endif
