/**********************************************************************
** Program Name: Final Project 
** Author: Brenna Smith
** Date: 03/19/2018
** Description: This is the main program that keeps running the alien 
** game until the user dies or wins the game.       
***********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AlienGame.hpp"
#include "Menu.hpp"
#include "inputValid.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::srand;
	

int main(){
	
	srand(time(NULL));


	AlienGame game;

	//While they haven't lost or won yet
	while (!game.getStatus()) {
		
		game.move();
		
	}	


	return 0;
}

