
/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class implementation file for the ItemSpace
 * class which is a subclass of the Space class.
 **********************************************************************/

#include "ItemSpace.hpp"
#include "Menu.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

//Set name of room
ItemSpace::ItemSpace(string newName) {
	name = newName;
}	

//Pick a random item and add to backpack  
int ItemSpace::enterRoom(vector<Item> &backpack) {
	int randNum; 
	Item newItem;
	string name = "";
	bool inBag, success = false;
//	cout << "You've found an item!" << endl;
	
	//Until we find an item that is not in the pack
	while (!success) {
		randNum = rand() % 12; 
		inBag = false;

		if (randNum < 2) {
			//Comms beacon - required item
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == comm) {
					inBag = true;	
				}		
			}	  
			
/*			//check the saved items
			for (int i = 0; i < saved.size(); i++) {
				if (saved[i] == comm) {
					inBag == true;	
				}		
			}
*/				  
			if (!inBag) {
				cout << "You've found the communication beacon!" << endl;
				cout << "This item will allow the rescue team to find you on the shuttle." << endl; 
				name = "Communication Beacon";
				newItem = comm;
				success = true;
			}
					
		} else if (randNum == 2 || randNum == 3) {
			//Hyper Sleep - required item
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == shot) {
					inBag = true;	
				}		
			}	  
			
/*			//check the saved items
			for (int i = 0; i < saved.size(); i++) {
				if (saved[i] == shot) {
					inBag == true;	
				}		
			}
*/
			if (!inBag) {
				cout << "You've found the hypersleep shot!" << endl;
				cout << "This item will allow you to go into hypersleep once on the shuttle." << endl; 
				name = "Hypersleep Shot";
				newItem = shot;
				success = true;
			}
				
		} else if (randNum == 4 || randNum == 5) {
			//Jonesy the cat - required item
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == cat) {
					inBag = true;	
				}		
			}	  
			
			if (!inBag) {
				cout << "You hear a sound coming from the vents above. You prepare yourself for battle waiting impatiently..." << endl;
				cout << "The sound grows louder until.. OH NO! The vent behind you bursts open! " << endl; 
				cout << "Phew, it's just your cat, Jonesy! He is the only other survivor on the Nostromo." << endl;
				cout << "You must save him by getting him onto the shuttle." << endl; 
				
				name = "Jonesy";
				newItem = cat;
				success = true;
			}
				
		} else if (randNum == 6 || randNum == 7) {
			//Fuel
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == fuel) {
					inBag = true;	
				}		
			}	  
			
			if (!inBag) {
				cout << "You've found fuel for your flamethrower!" << endl;
				cout << "Use fuel to add uses to your flamethrower (up to 2 uses at once)." << endl; 
				name = "Flamethrower Fuel";
				newItem = fuel;
				success = true;
			}
						
		} else if (randNum == 8 || randNum == 9) {
			//Bandages
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == bandages) {
					inBag = true;	
				}		
			}	  
			
			if (!inBag) {
				cout << "You've found some bandages!" << endl;
				cout << "Use bandages to heal any injuries (+2 to health)." << endl; 
				name = "Bandages";
				newItem = bandages;
				success = true;
			}
						
		} else if (randNum == 10 || randNum == 11) {
			//Adrenaline
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == adrenaline) {
					inBag = true;	
				}		
			}	  
			
			if (!inBag) {
				cout << "You've found an adrenaline shot!" << endl;
				cout << "Use an adrenaline shot to speed things up. (Make it to 2 rooms in 1 round.)" << endl; 
				name = "Adrenaline Shot";
				newItem = adrenaline;
				success = true;
			}	
		}		
	}

	//Once item is found, put it in the backpack 
	if (backpack.size() < 5) { 
		backpack.push_back(newItem);
		cout << "It has been added to your backpack." << endl;	
	} else {
		//If backpack is full, the user must remove an item or discard new one
		Menu discard;
		for (int i = 1; i < 5; i++) {
			if (backpack[i] == comm) { 
				discard.addOption("Comms Beacon");
			} else if (backpack[i] == shot) {
				discard.addOption("Hypersleep Shot");
			} else if (backpack[i] == cat) {
				discard.addOption("Jonesy");
			} else if (backpack[i] == fuel) {
				discard.addOption("Flamethrower Fuel");
			} else if (backpack[i] == bandages) {
				discard.addOption("Bandages");
			} else if (backpack[i] == adrenaline) {
				discard.addOption("Adrenaline Shot");
			}		
		}	
		discard.addOption(name);
		
		cout << "Unfortunately, your backpack is full.";
		cout << "You must discard an item. (It may not be here when you return.)" << endl; 
		discard.displayOptions("What item are you going to drop?");
		
		int choice = discard.getChoice();
		if (choice != 5) {
			//Replace new item with chosen item
			backpack[choice] = newItem;	
		}	 
	}

	return 0;
}	
