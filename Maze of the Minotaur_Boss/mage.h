/*
Author:         Aaron Meche
Program:        Homework 6 - Challenge of the Minotaur Turn-Based RPG - mage.h
Description:    This is the header file for the Mage class, derived from the Character class
Date Due:       03/19/19
Date Created:   03/07/19
Date Last Mod:  03/17/19
Input:          N/A
Process:        N/A
Output:         N/A
Assumptions:    That the character.h and mintoaur.h files exist and are in the same folder
*/

#pragma once
#include "character.h"
#include "minotaur.h"
#include <iostream>
#include <string>

class Mage : public Character
{
public:
	Mage(string iname);							// Mage constructor
	~Mage();									// Mage destructor
	string getName();							// get function for the name
	void setName(string iname);					// set function for the name
	void setMage(bool input);					// sets the mage bool to true
	bool getMage();								// gets the mage bool value
	bool getFrozen();							// gets the frozen value, which is a status effect in the 'Blizzard" mage option
	void setFrozen(bool f);						// sets the frozen value
	void offense(Mage&, Minotaur&, int choice);	// offense function for the mage vs minotaur fight
	void defense(Mage&, Minotaur&, int choice);	// defense function for the mage vs minotaur fight

private:
	string name;
	bool mage;
	bool frozen;
};