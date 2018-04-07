

/**********************************************************************
 * Program Title: Text Based Game - Final 
 * Author: Brenna Smith
 * Date: 3/10/2018
 * Description: This is the class implementation file for the AlienGame
 * class which is contains the main functionality of the game, including
 * the "board", health, timer, and backpack of supplies.  
 **********************************************************************/

#include "AlienGame.hpp"
#include "ItemSpace.hpp"
#include "AlienSpace.hpp"
#include "EventSpace.hpp"
#include "EscapeSpace.hpp"
#include "Menu.hpp"
#include "inputValid.hpp"

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
    
/*vector<Item> backpack;
 int health;
int timer;
Space* current;
Space* shuttle;
*/				

AlienGame::AlienGame() {
	timer = 20;
	health = 20;
	gameOver = false;
	backpack.push_back(full); 
	setup();
}	

//Deallocate all created spaces
AlienGame::~AlienGame() {
	current = shuttle->getUp();
	current = current->getLeft();
	current = current->getDown();
	delete current->getUp();					//Delete medical
	delete current->getRight();					//Delete electrical
	delete current->getLeft();					//Delete cockpit
	delete current->getDown();					//Delete cafeteria
	delete current;							//Delete central junction
	delete shuttle->getUp();						//Delete Engineering
	delete shuttle->getDown();					//Delete Rec
	delete shuttle;							//Delete escape;
	

	shuttle = nullptr; 
	current = nullptr;
}

void AlienGame::setup() {
	//create pointers for all rooms and choose random space types 
	Space* cockpit = randomType("Cockpit");
	Space* central = randomType("Central Junction");
	Space* medical = randomType("Medical Bay");
	Space* cafeteria = randomType("Cafeteria");
	Space* electrical = randomType("Electrical Closet");
	Space* engine = randomType("Engineering Bay");
	Space* rec = randomType("Recreation Hall"); 
	shuttle = new EscapeSpace("Escape Shuttle");
	
	//Set the relations between the rooms 
	cockpit->setRight(central);
	central->setUp(medical);
	central->setDown(cafeteria);
	central->setRight(electrical);
	medical->setRight(engine);
	engine->setDown(shuttle);
	cafeteria->setRight(rec);
	rec->setUp(shuttle);

	//User starts in the cockpit 
	current = cockpit;

	//Set pointers to null
	central = nullptr;;
	medical = nullptr;
	cafeteria = nullptr;
	electrical = nullptr;
	engine = nullptr;
	rec = nullptr; 
	cockpit = nullptr;

	//Introduce the game
	cout << "Welcome to 'Alien: The C++ Game'!" << endl;
	cout << endl;
	cout << "In this game you are Ellen Ripley, a warrant officer aboard the cargo star ship Nostromo." << endl; 
	cout << endl;
	cout << "Your crew have all lost their lives to a Xenomorph running rampant onboard." << endl;
	cout << "As a last ditch effort, you are attempting to blow up the Nostromo with the alien on board. " << endl;
	cout << endl;
	cout << "In order to escape with your life, you must gather these items from the ship and take them all to " << endl;
	cout << "the escape shuttle located in the back of the ship: " << endl;
	cout << "1. A communications beacon to alert any nearby ships of your presence on the shuttle." << endl;
	cout << "2. A shot that will put you into hypersleep after you board the shuttle." << endl;
	cout << "3. Your only living crewmate - Jonesy the Cat" << endl;
	cout << endl;
	cout << "After you gather these 3 items, book it to the escape shuttle before the Nostromo detonates and" << endl;
	cout << "before you succumb to any wounds." << endl;
	cout << "You'll find these 3 items and more you can use along the way. Be careful though! " << endl;
	cout << "In space, no one can hear you scream... " << endl;
	cout << endl;
}	

//This function chooses a random space type to assign a room (item, alien, or event)
Space* AlienGame::randomType(string newName) {
	int type = rand() % 4;
	Space* room;

	if (type == 0) {
		room = new EventSpace(newName);
	} else if (type == 1) {
		room = new AlienSpace(newName);
	} else {
		room = new ItemSpace(newName);
	}			
		
	return room;
}	

//This function allows the user to choose which room they want to move into, then
//interacts with that room based on the space type
void AlienGame::move() {
	printShip();
	
	Menu movement;
	string temp;
	int up, down, left, right, choice;
	up = down = left = right = -1; 
	choice = 0;

	cout << "You are in the " << current->getName() << "." << endl;

	//Find the viable options
	if (current->getUp() != nullptr) {
		temp = "Move up to the " + (current->getUp())->getName();
		up = movement.addOption(temp);
	} 
	
	if (current->getRight() != nullptr) {
		temp = "Move right to the " + (current->getRight())->getName();
		right = movement.addOption(temp);
	}
	
	if (current->getDown() != nullptr) {
		temp = "Move down to the " + (current->getDown())->getName();
		down = movement.addOption(temp);
	}
	
	if (current->getLeft() != nullptr) {
		temp = "Move left to the " + (current->getLeft())->getName();
		left = movement.addOption(temp);
	}
	
	movement.displayOptions("Where would you like to go next?");
	choice = movement.getChoice();	 

	if (choice == up) {
		current = current->getUp();
	} else if (choice == right) {
		current = current->getRight();	
	} else if (choice == down) {
		current = current->getDown();
	} else if (choice == left) {
		current = current->getLeft();
	} else {
		cout << "There was an error trying to move rooms." << endl;
	}

	//Enter the new room. If escape shuttle, see if all necessary items are present
	if (current != shuttle) {
		int damage = current->enterRoom(backpack);
		
		if (health + damage <= 20) {
			health += damage;
		}

		leaveRoom();

	} else {
		if (current->enterRoom(backpack) == 1) {
			gameOver = true;
			cout << endl;
			cout << "You seal off the shuttle and prepare to break away from the Nostromo. " << endl;
			cout << "As you are released and begin to fly away you see the Nostromo explode just as you have "<< endl;
			cout << "reached a safe distance. The xenomorph is dead! You now have a long trek ahead in hopes that " << endl;
			cout << "another ship will see your beacon and come to rescue you. You put Jonesy in a hypersleep pod " << endl;
			cout << "next to yours, then give yourself the shot that will keep you asleep until help arrives, before " << endl;
			cout << "climbing into a pod of your own." << endl;      
			cout << "Your eyes become heavy as you think of returning to your daughter's arms and take solace in the fact" << endl;
			cout << "that you'll never have to face a nightmare like this again.... "<< endl;
			cout << endl; 
		} else {
			leaveRoom();	
		}		
	}	
}	


void AlienGame::leaveRoom() {
	timer--; 
	char answer = ' ';
	int beacon, jones, sleep, band, fire, speed, other;
	beacon = jones = sleep = band = fire = speed = other = 0;
	bool itemUsed = false; 
	Space* temp;

	//Check for health and timer above zero and 
	if (health <= 0) {
		cout << "Your wounds are overwhelming and your vision starts to fade. You collapse to the floor." << endl;
		cout << "You wake suddenly with your chest burning. You try to move but are cemented. You begin to hyperventilate " << endl;
		cout << "as your chest erupts, and a pale creature bursts forth.  " << endl;
		cout << "GAME OVER, MAN! GAME OVER!" << endl;;
		gameOver = true;
	} else if (timer == 0) {
		cout << "MOTHER: Automatic destruction in 3... 2... 1... BOOOOOOM! " << endl;
		cout << "GAME OVER, MAN! GAME OVER!" << endl;
		gameOver = true;
	} else {
	//If stats are both good	
		cout << endl;
		cout << "MOTHER: Ship will automatically destruct in T minus " << timer << " minutes." << endl;  	
		cout << endl;
		cout << "You have " << health << " health remaining." << endl;
		cout << "Would you like to use an item before moving forward? "; 

		while (answer != 'y' && answer != 'n') {
			cout << "Y or N? " << endl;	
			answer = validChar();
		}

		//If the user wants to use one of their items 
		if (answer == 'y') {
			//Create a menu with the required items
			Menu useItem;
			for (int i = 1; i < backpack.size(); i++) {
				if (backpack[i] == comm) { 
					beacon = useItem.addOption("Comms Beacon");
				} else if (backpack[i] == shot) {
					sleep = useItem.addOption("Hypersleep Shot");
				} else if (backpack[i] == cat) {
					jones = useItem.addOption("Jonesy");
				} else if (backpack[i] == fuel) {
					fire = useItem.addOption("Flamethrower Fuel");
				} else if (backpack[i] == bandages) {
					band = useItem.addOption("Bandages");
				} else if (backpack[i] == adrenaline) {
					speed = useItem.addOption("Adrenaline Shot");
				}		
			}	

			other = useItem.addOption("Don't use any items.");
			
			//While they haven't chosen a valid item
			while (!itemUsed) {
				useItem.displayOptions("What item would you like to use?");
		
				int choice = useItem.getChoice();
		
				if (choice == beacon || choice == sleep || choice == jones) {
					cout << "You can't use this item, you need it to escape!" << endl; 
									
				} else if (choice == band) {
					cout << "You stop for a moment to assess your wounds and apply bandages where needed. " << endl; 
				
					if (health + 10 > 20) {
						health = 20;	
					} else {
						health += 10;
					}
				
					cout << "Your health is now " << health << "." << endl;  	
					itemUsed = true;
					backpack.erase(backpack.begin() + band);

				} else if  (choice == fire) {
					if (backpack[0] == empty) {
						backpack[0] = half;
						itemUsed = true;
						backpack.erase(backpack.begin() + fire);
					} else if (backpack[0] == half) {
						backpack[0] = full;
						itemUsed = true;
						backpack.erase(backpack.begin() + fire);
					} else {				//backpack[0] == full 
						cout << "You flamethrower is already full. Save your fuel for later!" << endl;
					}		

				} else if (choice == speed) {
					timer++;
					cout << "You stab the adrenaline needle into a vein and feel energized again." << endl;
					cout << "(You have one additional second on the clock.)" << endl;  
					itemUsed = true;				
					backpack.erase(backpack.begin() + speed);
				
				} else if (choice == other) {
					itemUsed = true;	
				}	 
			}	
		}	
	
		//Change the type of space that this room is so it changes everytime unless it's the escape pod
		if (current != shuttle) {
			temp = randomType(current->getName());
			
			if (current->getUp() != nullptr) {			
				temp->setUp(current->getUp());
			}
		
			if (current->getRight() != nullptr) {			
				temp->setRight(current->getRight());
			}
			
			if (current->getDown() != nullptr) {			
				temp->setDown(current->getDown());
			}
			
			if (current->getLeft() != nullptr) {			
				temp->setLeft(current->getLeft());
			}

			delete current;
			current = temp;
			temp = nullptr;    	 
		}
	}			
}	
	

//Prints the ascii version of the ship	
void AlienGame::printShip() {
	cout << endl;
	cout << "		     ______             ___________ " << endl;
  	cout << "		    /       \\__________/           \\_____ " << endl;
        cout << "		    |Medical|__________|Engineering|__   \\ " << endl;
	cout << "  		    \\_______/          \\___________/  \\   \\ " << endl;
	cout << "                      |  |                             \\   \\     " << endl;
	cout << "   ______           __|__|__                            \\   \\       ____  " << endl;
	cout << " _/      \\_________/        \\            __________      \\___\\_____/    | " << endl;
	cout << "/ Cockpit |       | Central  |----------|Electrical|     |   Escape     | " << endl;
	cout << "\\_        |_______| Junction |----------|__Closet__|     |_______Pod    | "  << endl;
	cout << "  \\______/         \\________/                            /   /     \\____| " << endl;
	cout << "                      |  |                              /   /	" << endl;
	cout << "                   ___|__|___           ___________    /   /   " << endl;
	cout << "                  /          \\_________/           \\__/   /    " << endl;
	cout << "                 | Cafeteria |_________|Recreation |_____/     " << endl;  
	cout << "                  \\__________/         \\___________/           " << endl;
	cout << endl;

}		
	
bool AlienGame::getStatus() {
		
	return gameOver;
}			
