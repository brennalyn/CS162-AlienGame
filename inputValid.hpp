

/**********************************************************************
** Program Name: Input Validation 
** Author: Brenna Smith
** Date: 01/25/2018
** Description: this is the header file for the input validation
***********************************************************************/

#ifndef INPUTVALID_HPP
#define INPUTVALID_HPP

#include <string>
using std::string;

enum inputData { wholeNum, character};

string chooseType(inputData choice);

int validInt();
double validDouble();
char validChar();
string validString();
	
#endif
