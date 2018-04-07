/**********************************************************************
 * Program Title: Portable Menu 
 * Author: Brenna Smith
 * Date: 1/15/2018
 * Description: This is the class header file for the menu class
 **********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

using std::vector;
using std::string;

class Menu {

        private:
		vector<string> options;

	public:
		int addOption(string output);	
		void displayOptions(string prompt);
		void removeOptions();
		int getChoice();
		int getInt(string prompt);
		string getString(string prompt);
};
#endif

